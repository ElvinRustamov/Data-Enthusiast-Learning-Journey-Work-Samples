// What is a vector: An array that can grow and shrink in size at execution time

#include <vector>
#include <iostream>

int main() {
//    std::vector <char> vowels;
//    std::cout << vowels[0];

    std::vector <char> vowels {'a', 'e', 'i'};
    std::cout << vowels[1] << std::endl;
    std::cout << vowels[10] << std::endl;

    std::cout << vowels.at(2) << std::endl;
    std::cout << "Size of vector:" << vowels.size() << std::endl;

    char add_vowel = 'o';
    std::cin >> add_vowel;

    vowels.push_back(add_vowel);
    std::cout << "Size of vector:" << vowels.size() << std::endl;
    return 0;
}