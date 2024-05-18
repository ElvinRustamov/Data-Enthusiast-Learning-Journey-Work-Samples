#include <iostream>
#include <vector>

// Global new_array to store the sorted elements
std::vector<int> new_array;

void selectionSort(std::vector<int>& l) {
    while (!l.empty()) {
        int element = l.at(0);
        int idx = 0;

        // Find the minimum element and its index
        for(int i = 0; i < l.size(); i++) {
            if (element > l.at(i)) {
                element = l.at(i);
                idx = i;
            }
        }

        // Add the minimum element to new_array
        new_array.push_back(element);

        // Remove the minimum element from l
        l.erase(l.begin() + idx);
    }

    std::cout << "Process finished" << std::endl;
}

int main() {
    std::vector<int> sample_list = {5, 3, 2, 7, 9, 8};
    std::vector<int> copy_list(sample_list.begin(), sample_list.end());

    selectionSort(copy_list);

    std::cout << "Original array: ";
    for (const auto& e : sample_list) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted array: ";
    for (const auto& e : new_array) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}