// Functions (Pass by Reference)

// The formal parameter will now be an alias for the actual parameter

// Reference -> &

#include <iostream>

void scale_number(int &num);

void pass_by_ref(std::string &s) {
    s = "Changed";
}

int main () {
    int number = 1000;
    std::cout << number << std::endl;
    scale_number(number);
    std::cout << number << std::endl;

    std::string s = "Unchanged";
    std::cout << s << std::endl;
    pass_by_ref(s);
    std::cout << s << std::endl;
    return 0;
}

void scale_number(int &num) {
    if (num > 100) {
        num = 100;
    }
}