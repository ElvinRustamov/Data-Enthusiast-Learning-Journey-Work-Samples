// C++ Primer 5th Edition
// Chapter 1

#include <iostream>

int main () {
//    std::cout << "Enter two numbers: " << std::endl;
//    int n1 = 0, n2 = 0;
//    std::cin >> n1 >> n2;
//    std::cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << std::endl;


    // Flow of Control
//    int sum = 0, val = 50;
//    while (val <= 100) {
//        sum += val;
//        ++val;
//    }
//    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

//  Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
//    std::cout << "Enter two numbers: ";
//    int n1 = 0, n2 = 0;
//    std::cin >> n1 >> n2;
//    int start_num = n1;
//    int sum = 0;
//    while (n1 <= n2) {
//        sum += n1;
//        ++n1;
//    }
//    std::cout << "Sum of " << start_num << " to " << n2 << " inclusive is " << sum << std::endl;

    // The for statement
//    int sum = 0;
//    for (int val=1; val <= 10; ++val) {
//        sum += val;
//    }
//    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

//    int sum = 0, value = 0;
//    while (std::cin >> value) {
//        sum += value;
//    }
//    std::cout << "Sum is: " << sum << std::endl;

    // The if Statement
    int currVal =0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt - 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}