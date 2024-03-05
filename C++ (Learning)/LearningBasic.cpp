// This is a single line comment

/*This
 is
 a
 multi-line
 comment.
*/

#include <iostream>

int main() {
//     std::cout << "Hello world!"; // Next output starts at the end.
//     std::cout << "Hello world!" << std::endl; // endl == \n
//
//     std::cout << "Hello " << "world!" << std::endl;
//     std::cout << "Hello\nOut\nThere";

    int num1;
    int num2;
    double num3;

//    std::cout << "Enter an integer:";
//    std::cin >> num1;
//    std::cout << "You entered: " << num1 << std::endl;

//    std::cout << "Enter first integer:";
//    std::cin >> num1;
//
//    std::cout << "Enter second integer:";
//    std::cin >> num2;
//
//    std::cout << "Numbers are: " << num1 << " and " << num2 << std::endl;

    std::cout << "Enter a double:";
    std::cin >> num3;

    std::cout << "You entered:" << num3;
    return 0; // The C++ main function must return 0 when the program terminates successfully.
}