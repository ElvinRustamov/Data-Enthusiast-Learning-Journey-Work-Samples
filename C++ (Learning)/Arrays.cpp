// What is an array: Compound data type or data structure (collection of elements)
// All elements are of the same type
// Each element can be accessed directly

#include <iostream>

int main() {
//    char vowels[] {'a', 'e', 'b', 'c', 'd'};
//    std::cout << "The first vowel is: " << vowels[0] << std::endl;

//    double high_temps[] {90.1, 89.8, 77.5, 69.3};
//    std::cout << "First high temperature is: " << high_temps[0] << std::endl;
//    high_temps[0] = 100.1;
//    std::cout << "First high temperature is now: " << high_temps[0] << std::endl;

    int test_scores[5] {}; // initializes all to 0. Always initialize your arrays!
    std::cout << test_scores[0] << std::endl;

    std::cout << "Enter 5 scores:";
    std::cin >> test_scores[0];
    std::cin >> test_scores[1];
    std::cin >> test_scores[2];
    std::cin >> test_scores[3];
    std::cin >> test_scores[4];

    std::cout << test_scores[0] << std::endl;
    return 0;
}