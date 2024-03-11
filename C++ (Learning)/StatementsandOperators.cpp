#include <iostream>

int main() {
    // Assignment operator (=)
//    int num1 = 10; // initialization (variable gets value first time)
//    int num2 = 20;

//    num1 = 100;
//    num1 = num2 = 1000; // right to left
    // num1 = 'some text'; // it didn't give me an error but a trash value.

    // std::cout << "num1 is " << num1 << std::endl;
    // std::cout << "num2 is " << num2 << std::endl;

    /* Arithmetic Operators
     + addition
     - subtraction
     * multiplication
     / division
     % modulo or remainder (works only with integers)
     */

//    int result = 0;
//    result = num1 + num2;
//    std::cout << num1 << " + " << num2 << " = " << result << std::endl;
//
//    result = num1 - num2;
//    std::cout << num1 << " - " << num2 << " = " << result << std::endl;
//
//    result = num1 * num2;
//    std::cout << num1 << " * " << num2 << " = " << result << std::endl;
//
//    result = num1 / num2;
//    std::cout << num1 << " / " << num2 << " = " << result << std::endl;
//
//    result = num2 / num1;
//    std::cout << num2 << " / " << num1 << " = " << result << std::endl;
//
//    result = num1 % num2;
//    std::cout << num1 << " % " << num2 << " = " << result << std::endl;
//
//    result = num2 % num1;
//    std::cout << num2 << " % " << num1 << " = " << result << std::endl;


    // Convert EUR to USD
//    const double usd_per_eur = 1.9;
//    std::cout << "Welcome to the EUR to USD converter!" << std::endl;
//    std::cout << "Enter the value in EUR:";
//
//    double euros = 0.0;
//    double dollars = 0.0;
//
//    std::cin >> euros;
//    dollars = euros * usd_per_eur;
//
//    std::cout << euros << " euros is equivalent to " << dollars << " dollars\n";

    /*
     Increment operator ++
     Decrement operator --
     Notation:
     - Prefix ++num
     - Postfix num++

     Don't overuse this operator!
     */

//    int counter = 10;
//    int result = 0;
//
//    std::cout << "Counter " << counter << std::endl;
//    counter++;
//    std::cout << "Counter " << counter << std::endl;
//
//    ++counter;
//    std::cout << "Counter " << counter << std::endl;
//
//    result = ++counter; // counter = counter + 1; result = counter;
//    std::cout << "Counter " << counter << std::endl;
//    std::cout << "Result " << result << std::endl;
//
//
//    result = counter++; // result = counter; counter = counter + 1;
//    std::cout << "Counter " << counter << std::endl;
//    std::cout << "Result " << result << std::endl;

// Type Coercion: conversion of one operand to another data type.
// Promotion: conversion to a higher type
// Demotion: conversion to a lower type

//    int total = 0;
//    int num1 = 0;
//    int num2 = 0;
//    int num3 = 0;
//    const int count = 3;
//
//    std::cout << "Enter 3 integers (separated by space):";
//    std::cin >> num1 >> num2 >> num3;
//    total = num1 + num2 + num3;
//
//    double average = 0.0;
////    average = total / count;
//    average = static_cast<double>(total) / count;
//
//    std::cout << "The 3 numbers were:" << num1 << "," << num2 << ","  << num3 << std::endl;
//    std::cout << "The sum of the numbers is: " << total << std::endl;
//    std::cout << "The average of the numbers is: " << average;

// Testing for Equality
// The == and != operators (Evaluates to a Boolean (True or False, 1 or 0)

//    bool equal_result = false;
//    bool not_equal_result = false;
//    int num1 = 0;
//    int num2 = 0;
//
//    std::cout << std::boolalpha; // will display true/false instead of 0/1 for booleans
//
//    std::cout << "Enter two integers separated by space:";
//    std::cin >> num1 >> num2;
//    equal_result = (num1 == num2);
//    not_equal_result = (num1 != num2);
//
//    std::cout << "Comparision result (equals): " << equal_result << std::endl;
//    std::cout << "Comparision result (not equals): " << not_equal_result << std::endl;

// Relational operators
// <=> three-way comparison (C++20)
//    int num1 = 12;
//    int num2 = 20;
//    std::cout << (num1 > num2) << std::endl;
//    std::cout << (num1 < num2) << std::endl;

// Logical operators
// not -> ! (unary operator)
// and -> && (binary operator)
// or -> || (binary operator)
// Short-Circuit Evaluation: When evaluating a logical expression C++ stops as soon as the result is known.

    int num = 0;
    const int lower = 10;
    const int upper = 20;

    std::cout << std::boolalpha;
    std::cout << "Enter an integer - the bounds are " << lower << " and " << upper << ":";
    std::cin >> num;
    bool within_bounds = false;
    within_bounds = (num > lower && num < upper);
    std::cout << within_bounds;
    return 0;
}