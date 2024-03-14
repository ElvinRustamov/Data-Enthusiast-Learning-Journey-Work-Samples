// Function Overloading

#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector<std::string>);

void print(int num) {
    std::cout << "Printing int: " << num << std::endl;
}

void print(double num) {
    std::cout << "Printing double: " << num << std::endl;
}

void print(std::string s) {
    std::cout << "Printing string: " << s << std::endl;
}

void print(std::string s, std::string s1) {
    std::cout << "Printing 2 strings: " << s << "," << s1 << std::endl;
}

void print(std::vector<std::string> v) {
    std::cout << "Printing vector of strings:";
    for (auto i: v) {
        std::cout << i << std::endl;
    }
}
int main () {
//    print(100);
//    print('A'); // chracter is always promoted to int should print 65 ASCII ('A')

//    print(5.3);
//    print(23.6F);

//    print("String");
//
//    print("String1 ", "String2");

    std::vector<std::string> s = {"a", "b", "c", "d"};
    print(s);

    return 0;
}