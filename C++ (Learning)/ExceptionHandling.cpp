#include <iostream>
class Printer {
    std::string name;
    int available_paper;

public:
    Printer(std::string name, int paper) {
        name = name;
        available_paper = paper;
    }
    void Print(std::string txt) {
        int required_paper = txt.length() / 10;

        if (required_paper > available_paper) {
            throw "Not enough paper";
        } else {
        std::cout << "Printing ... " << txt <<std::endl;
        available_paper -= required_paper;
        }
    }
};


int main() {
    Printer my_printer("Printer 1", 10);
    try {
        my_printer.Print("Hello, I am learning exception handling in C++");
        my_printer.Print("Hello, I am learning exception handling in C++");
        my_printer.Print("Hello, I am learning exception handling in C++");
    }
    catch (const char * txtException) {
        std::cout << "Exception: " << txtException << std::endl;
    }
    catch (int exCode) {
        std::cout << "Exception: " << exCode << std::endl;
    }
    catch (...) { // Handle all types of exceptions.
        std::cout << "Exception happaned!" << std::endl;
    }

    return 0;
}