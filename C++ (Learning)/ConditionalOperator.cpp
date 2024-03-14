// Conditional Operator

/*
    (cond_expr) ? expr1 : expr2

- If condition is true then the value of expr1 is returned
- If condition is false then the value of expr2 is returned

- Ternary operator
- Similar to if-else construct
- Very useful when used inline
*/

#include <iostream>

int main () {
//    int score = 90;
//    std::cout << ((score > 90) ? "Excellent" : "Good");
    int num1 = 0, num2 = 0;
    std::cout << "Enter two integers separated by a space:";
    std::cin >> num1 >> num2;
    if (num1 != num2) {
        std::cout << "Largest: " << ((num1 > num2) ? num1 : num2) << std::endl;
        std::cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << std::endl;
    } else {
        std::cout << "The numbers are the same" << std::endl;
    }

    return 0;
}