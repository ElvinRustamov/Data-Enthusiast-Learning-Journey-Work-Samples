import cv2
import mediapipe as mp
import numpy as np
import time
import csv
import matplotlib.pyplot as plt

mp_face_mesh = mp.solutions.face_mesh

# LEFT_IRIS = [468, 469, 470, 471]
# RIGHT_IRIS = [473, 474, 475, 476]
LEFT_EYE = [33, 133, 159, 145]
RIGHT_EYE = [362, 263, 386, 374]

LEFT_IRIS = [469, 470, 471, 472]
RIGHT_IRIS = [474, 475, 476, 477]

# LEFT_EYE = [33, 246, 161, 160, 159, 158, 157, 173, 133]
# RIGHT_EYE = [362, 398, 384, 385, 386, 387, 388, 466, 263]

zone_counts = {f"{r}-{c}": 0 for r in ["Top", "Mid", "Bottom"] for c in ["Left", "Center", "Right"]}
ema_alpha = 0.25
ema_point = None

def get_center(landmarks, indices):
    points = np.array([(landmarks[i].x, landmarks[i].y) for i in indices])
    center_norm = np.mean(points, axis=0)
    return center_norm

def get_eye_corners(landmarks, indices):
    left = landmarks[indices[0]]
    right = landmarks[indices[1]]
    top = landmarks[indices[2]]
    bottom = landmarks[indices[3]]
    return left, right, top, bottom

def get_offset_ratio(iris_center_norm, left_norm, right_norm, top_norm, bottom_norm):
    eye_cx_norm = (left_norm.x + right_norm.x) / 2.0
    eye_cy_norm = (top_norm.y + bottom_norm.y) / 2.0
    width_norm = abs(right_norm.x - left_norm.x) + 1e-6
    height_norm = abs(bottom_norm.y - top_norm.y) + 1e-6

    x_offset = (iris_center_norm[0] - eye_cx_norm) / width_norm
    y_offset = (iris_center_norm[1] - eye_cy_norm) / height_norm
    y_offset = -y_offset  # Flip Y for correct upward gaze
    return x_offset, y_offset

def direction_from_offset(x_offset, y_offset, threshold=0.12):
    horizontal = "Left" if x_offset < -threshold else "Right" if x_offset > threshold else "Center"
    vertical = "Top" if y_offset > threshold else "Bottom" if y_offset < -threshold else "Mid"
    return horizontal, vertical

def get_zone(x_pixel, y_pixel, w, h):
    row = "Top" if y_pixel < h // 3 else "Mid" if y_pixel < 2 * h // 3 else "Bottom"
    col = "Left" if x_pixel < w // 3 else "Center" if x_pixel < 2 * w // 3 else "Right"
    return f"{row}-{col}"

cap = cv2.VideoCapture(0)
ret, frame = cap.read()
if not ret:
    print("Error: Could not read frame from camera.")
    exit()
frame_h, frame_w = frame.shape[:2]
heatmap = np.zeros((frame_h, frame_w, 3), dtype=np.uint8)
gaze_positions = []

csv_file = open('gaze_log.csv', mode='w', newline='')
csv_writer = csv.writer(csv_file)
csv_writer.writerow(['timestamp', 'x_offset', 'y_offset', 'horizontal', 'vertical', 'zone', 'ema_x', 'ema_y'])

with mp_face_mesh.FaceMesh(
    max_num_faces=1,
    refine_landmarks=True,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as face_mesh:

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            print("Stream end or error.")
            break

        frame = cv2.flip(frame, 1)
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        rgb.flags.writeable = False
        results = face_mesh.process(rgb)
        rgb.flags.writeable = True
        frame_display = cv2.cvtColor(rgb, cv2.COLOR_RGB2BGR)
        blended = frame_display.copy()

        if results.multi_face_landmarks:
            mesh = results.multi_face_landmarks[0]
            landmarks = mesh.landmark

            left_iris_center_norm = get_center(landmarks, LEFT_IRIS)
            right_iris_center_norm = get_center(landmarks, RIGHT_IRIS)

            l_left, l_right, l_top, l_bottom = get_eye_corners(landmarks, LEFT_EYE)
            r_left, r_right, r_top, r_bottom = get_eye_corners(landmarks, RIGHT_EYE)

            lx_off, ly_off = get_offset_ratio(left_iris_center_norm, l_left, l_right, l_top, l_bottom)
            rx_off, ry_off = get_offset_ratio(right_iris_center_norm, r_left, r_right, r_top, r_bottom)

            x_offset = (lx_off + rx_off) / 2.0
            y_offset = (ly_off + ry_off) / 2.0

            horizontal, vertical = direction_from_offset(x_offset, y_offset)

            avg_iris_x_norm = (left_iris_center_norm[0] + right_iris_center_norm[0]) / 2.0
            avg_iris_y_norm = (left_iris_center_norm[1] + right_iris_center_norm[1]) / 2.0
            raw_gaze_pixel = (int(avg_iris_x_norm * frame_w), int(avg_iris_y_norm * frame_h))

            if ema_point is None:
                ema_point = raw_gaze_pixel
            else:
                ema_point = (
                    int(ema_alpha * raw_gaze_pixel[0] + (1 - ema_alpha) * ema_point[0]),
                    int(ema_alpha * raw_gaze_pixel[1] + (1 - ema_alpha) * ema_point[1])
                )

            ema_point = (max(0, min(frame_w - 1, ema_point[0])), max(0, min(frame_h - 1, ema_point[1])))

            zone = get_zone(ema_point[0], ema_point[1], frame_w, frame_h)
            zone_counts[zone] += 1
            gaze_positions.append((ema_point[0], ema_point[1]))

            csv_writer.writerow([time.time(), x_offset, y_offset, horizontal, vertical, zone, ema_point[0], ema_point[1]])

            cv2.circle(heatmap, ema_point, 10, (0, 0, 255), -1)
            heatmap = cv2.addWeighted(heatmap, 0.97, np.zeros_like(heatmap), 0.03, 0)
            blended = cv2.addWeighted(frame_display, 0.6, heatmap, 0.4, 0)

            cv2.putText(blended, f"Dir: {vertical}-{horizontal}", (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            cv2.putText(blended, f"Zone: {zone}", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            y_pos = 90
            for k, v in zone_counts.items():
                cv2.putText(blended, f"{k}: {v}", (10, y_pos), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)
                y_pos += 18

            left_iris_pixel = (int(left_iris_center_norm[0] * frame_w), int(left_iris_center_norm[1] * frame_h))
            right_iris_pixel = (int(right_iris_center_norm[0] * frame_w), int(right_iris_center_norm[1] * frame_h))
            cv2.circle(blended, left_iris_pixel, 2, (0, 255, 0), -1)
            cv2.circle(blended, right_iris_pixel, 2, (0, 255, 0), -1)

            eye_center_pixel = (int(avg_iris_x_norm * frame_w), int(avg_iris_y_norm * frame_h))

            arrow_length = 80
            magnitude = np.sqrt(x_offset ** 2 + y_offset ** 2) + 1e-6

            if magnitude < 0.05:
                end_x = eye_center_pixel[0]
                end_y = eye_center_pixel[1] - arrow_length // 2
            else:
                unit_dx = x_offset / magnitude
                unit_dy = y_offset / magnitude
                end_x = int(eye_center_pixel[0] + unit_dx * arrow_length)
                end_y = int(eye_center_pixel[1] + unit_dy * arrow_length)

            cv2.arrowedLine(blended, eye_center_pixel, (end_x, end_y), (0, 0, 255), 2, tipLength=0.3)

            cv2.imshow("Final Gaze Tracker", blended)
        else:
            cv2.imshow("Final Gaze Tracker", frame_display)

        if cv2.waitKey(1) & 0xFF == 27:
            break

cap.release()
cv2.destroyAllWindows()
csv_file.close()
print("Session ended, generating heatmap...")

zone_grid = np.zeros((3, 3), dtype=int)
zone_map = {
    "Top-Left": (0, 0), "Top-Center": (0, 1), "Top-Right": (0, 2),
    "Mid-Left": (1, 0), "Mid-Center": (1, 1), "Mid-Right": (1, 2),
    "Bottom-Left": (2, 0), "Bottom-Center": (2, 1), "Bottom-Right": (2, 2)
}

for zone_name, count in zone_counts.items():
    if zone_name in zone_map:
        r, c = zone_map[zone_name]
        zone_grid[r, c] = count

plt.figure(figsize=(6, 6))
plt.imshow(zone_grid, cmap='hot', interpolation='nearest', origin='upper')
plt.title("Gaze Zone Heatmap")
plt.xticks([0, 1, 2], ['Left', 'Center', 'Right'])
plt.yticks([0, 1, 2], ['Top', 'Mid', 'Bottom'])

for r in range(3):
    for c in range(3):
        plt.text(c, r, str(zone_grid[r, c]), ha='center', va='center', color='white' if zone_grid[r, c] > zone_grid.max() / 2 else 'black')

plt.colorbar(label='Gaze Frequency')
plt.savefig("zone_heatmap.png")
print("Heatmap saved to zone_heatmap.png")
