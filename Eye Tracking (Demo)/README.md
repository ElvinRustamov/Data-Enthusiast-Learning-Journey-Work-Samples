# Real-Time Gaze Tracking System

This project is a real-time gaze tracking application built with Python using OpenCV and MediaPipe. It detects the user's eye gaze direction and visualizes it on screen along with a zone-based heatmap.

## 🔍 Features

- Real-time eye tracking using webcam input
- Direction detection: Top, Mid, Bottom × Left, Center, Right
- EMA-smoothed gaze points for stability
- On-screen visualizations with gaze arrows
- Zone-based gaze frequency tracking
- Automatic CSV logging
- Heatmap generation on session end

## 🖥️ Demo

![Gaze Heatmap](zone_heatmap.png)

## 🧰 Requirements

- Python 3.7+
- OpenCV
- MediaPipe
- NumPy
- Matplotlib

Install dependencies:

```bash
pip install opencv-python mediapipe numpy matplotlib
