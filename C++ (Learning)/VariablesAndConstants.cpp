// Declaring Variables: VariableType VariableName;

/*
 Example:
 - int age;
 - double rate;
 - string name;

 Account someone_account; non C++ built-in types. OOP (I can create my own type)
 Person james;
 */

// C++ is case sensitive.

/* Initializing Variables
int age; uninitialized
int age = 21; C-like initialization
int age (21); Constructor initialization
int age {21}; C++11 list initialization syntax
 */

#include <iostream>

int main () {
    // This program will calculate the area of a room in square feet.
    double width = 0;
    double length = 0;
    std::cout << "Write width and length of the room (with space):";
    std::cin >> width;
    std::cin >> length;

    std::cout << width*length << std::endl;

    return 0;
};