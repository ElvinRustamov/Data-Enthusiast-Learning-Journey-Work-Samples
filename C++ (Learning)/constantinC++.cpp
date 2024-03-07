/*
 * Types of constants:
 * Literal constants
 * Declared constants (const keyword)
 * Constant expressions (constexpr keyword)
 * Enumerated constants (enum keyword)
 * Defined constants (#define) Don't use defined constants in Modern C++
*/

#include <iostream>

int main () {
    std::cout << "Hello, welcome to Carpet Cleaning Service" << std::endl << std::endl;
    std::cout << "How many rooms would you like cleaned?";

    int number_of_rooms = 0;
    std::cin >> number_of_rooms;

    const double price_per_room = 30;
    const double price_tax = 0.06;
    const int estimate_expiry = 30; // days

    std::cout << "\nEstimate for carpet cleaning service" << std::endl;
    std::cout << "Number of rooms: " << number_of_rooms << std::endl;
    std::cout << "Price per room: $" << price_per_room << std::endl;
    std::cout << "Cost: $" << price_per_room * number_of_rooms << std::endl;
    std::cout << "Tax: $" << price_per_room * number_of_rooms * price_tax << std::endl;
    std::cout << "===================================================\n";

    std::cout << "Total estimate: $" << (price_per_room * number_of_rooms) + (price_per_room * number_of_rooms * price_tax) << std::endl;
    std::cout << "This estimate is valid for " << estimate_expiry << " days" << std::endl;

    return 0;
}

