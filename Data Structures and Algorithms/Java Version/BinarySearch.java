import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BinarySearch {
    static void binearySearch(List<Integer> items, int target) {
        int step = 0;
        while (true) {
            int mid = items.size() / 2;
            if (items.get(mid) == target) {
                step += 1;
                System.out.println("Found at index " + mid + ", Steps: " + step);
                break;
            }
            if (mid == 0) {
                System.out.println("Nothing to find");
                break;
            }
            else if (target > items.get(mid)) {
                step += 1;
                items = new ArrayList<>(items.subList(mid, items.size()));
            } else if (target < items.get(mid)) {
                step += 1;
                items = new ArrayList<>(items.subList(0, items.size() - mid - 1));
            }
        }

    }
    public static void main(String[] args) {
        System.out.println("Binary Search");

        List<Integer> items = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        int target = 3;
        binearySearch(items, target);
    }
}
