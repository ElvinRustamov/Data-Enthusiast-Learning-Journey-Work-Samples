// enum

#include <iostream>

enum color {
    RED,
    GREEN,
    BLUE
}; // creating our own type

int main() {
    color c;
    c = RED;
//    c1 = YELLOW; There is no value 'YELLOW' in color.
    std::cout << c << std::endl;
    return 0;
}