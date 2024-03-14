//C++ Looping Constructs

// for loop
// range-based for loop

// while loop: check the condition at the beginning of every iteration
// do-while loop: check the condition at the end of every iteration

#include <iostream>
#include <vector>

int main() {
    // For loop

//    for (int i = 1; i <= 10; ++i) {
//        std::cout << i << std::endl;
//    }

//    for (int i = 1; i <= 10; i += 2) {
//        std::cout << i << std::endl;
//    }

//    for (int i = 10; i > 0; --i) {
//        std::cout << i << std::endl;
//    }

//    for (int i = 1; i <= 100; ++i) {
//        std::cout << i;
//        if (i % 10 == 0) {
//            std::cout << std::endl;
//        }
//        else {
//            std::cout<< " ";
//        }
//    }

//    for (int i = 1; i <= 100; ++i) {
//        std::cout << i;
//        std::cout << ((i % 10 == 0) ? "\n" : " ");
//    }

//    std::vector<int> nums = {10, 20, 30, 40, 50};
//    for (unsigned i = 0; i < nums.size(); ++i) {
//        std::cout << nums[i] << std::endl;
//    }


    // Range-based for Loop | for (var_type var_name: sequence) statement;
//    int scores[] = {10, 20, 30};
//    for (int score: scores) {
//        std::cout << score << std::endl;
//    }

//    for (auto score: scores) {
//        std::cout << score << std::endl;
//    }

    std::vector<double> temperatures = {87.8, 77.9, 80.0, 72.5};
    double average_temp = 0;
    double total = 0;

    for (auto t: temperatures) {
        total += t;
    }
    if (temperatures.size() != 0) {
        average_temp = total / temperatures.size();
        std::cout << "Average temperature: " << average_temp << std::endl;
    } else {
        std::cout << "Error, zero division.";
    }

    return 0;
}