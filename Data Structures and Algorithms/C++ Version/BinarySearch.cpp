#include <iostream>
#include <vector>
#include<tuple>

std::tuple<int, int> binarySearch (std::vector<int> items, int target) {
    int steps = 0;
    int idx = 0;

    while (true) {
        int mid = items.size() / 2;

        if (target == items[mid]) {
            steps += 1;
            idx += mid;
            std::tuple<int, int> t = {steps, idx};
            return t;
        }

        if (mid == 0) {
            std::tuple<int, int> t = {0, 0};
            return t;
        }

        else if (target > items[mid]) {
            steps += 1;
            items = std::vector<int>(items.begin() + mid + 1, items.end());
        }

        else if (target < items[mid]) {
            steps += 1;
            items = std::vector<int>(items.begin(), items.end() - mid - 1);
        }
    }

}

int main () {
    std::vector<int> items = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 9;

    std::tuple<int, int> result;
    int steps;
    int idx;

    result = binarySearch(items, target);
    steps = std::get<0>(result);
    idx = std::get<1>(result);

    std::cout << "Steps: " << steps << ", " << "Index of element: " << idx;
    return 0;
}