// Function

/*
- When we call a function we pass in data to that function
- In the function call they are called arguments
- In the function definition they are called parameters
- They must match in number, order, and in type
*/

#include <iostream>
#include <cmath>

int add_numbers(int a, int b)
{
    return a + b;
} // My function

char* say_hello_without_void () {
    return "Hello";
}

// Example function with no return -> use void keyword
/*
void function_name ()
{
    statement(s)
    return; // optional
}
*/

void prototype_function (); // function prototype

void say_hello () {
    std::cout << "Hello" << std::endl;
}

void area_circle () {
    double pi_value = 3.14;
    double radius = 0;

    std::cout << "Enter radius:";
    std::cin >> radius;

    std::cout << pi_value * radius * radius;
}

// Example with default arguments
// double calc_cost (double base_cost, double tax_rate = 0.06)

int main() {
//  std::cout << sqrt(400) << std::endl;

//   std::cout << add_numbers(20, 40) << std::endl;

//   say_hello();

//   area_circle();

//    char* test_ = 0;
//    test_ = say_hello_without_void();
//    std::cout << test_ << std::endl;

//    prototype_function();

    return 0;
}

void prototype_function () {
    std::cout << "Prototype function" << std::endl;
}