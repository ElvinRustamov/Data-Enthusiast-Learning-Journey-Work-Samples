// The sizeof operator

#include <iostream>
#include <climits>

int main () {
    std::cout << "Sizeof information" << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "char:" << sizeof(char) << " bytes" << std::endl;
    std::cout << "int:" << sizeof(int) << " bytes" << std::endl;
    std::cout << "unsigned int:" << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "short:" << sizeof(short) << " bytes" << std::endl;
    std::cout << "long:" << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long:" << sizeof(long long) << " bytes" << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << "float:" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:" << sizeof(long double) << " bytes" << std::endl;
    std::cout << "==============================" << std::endl;


    int age = 21;
    std::cout << sizeof(age) << std::endl;

    double wage = 22.14;
    std::cout << sizeof(wage) << std::endl;
    return 0;
}