//C++ Looping Constructs

// while loop: check the condition at the beginning of every iteration
// do-while loop: check the condition at the end of every iteration

// while (expression)
//     statement;

#include <iostream>
#include <vector>

int main() {
    // while loop

//    int num = 0;
//    std::cout << "Enter a positive integer - start the coundown:";
//    std::cin >> num;
//
//    while (num > 0) {
//        std::cout << num << std::endl;
//        --num;
//    }

//    int number = 0;
//    std::cout << "Enter an integer less than 100:";
//    std::cin >> number;
//
//    while(number >= 100) {
//        std::cout << "Enter an integer less than 100:";
//        std::cin >> number;
//    }

    // do-while loop

//    do {
//        statements;
//    } while (expression);

    char selection = 0;
    do {
        std::cout << "------------------------------" << std::endl;
        std::cout << "1. Do this" << std::endl;
        std::cout << "2. Do that" << std::endl;
        std::cout << "3. Do something else" << std::endl;
        std::cout << "Q: Quit" << std::endl;
        std::cout << "\n";

        std::cout << "Enter your selection:";
        std::cin >> selection;

        if (selection == '1') {
            std::cout << "Your code 1 - doing this" << std::endl;
        }
        else if (selection == '2') {
            std::cout << "Your code 2 - doing that" << std::endl;
        }
        else if (selection == '3') {
            std::cout << "Your code 3 - doing something else" << std::endl;
        }
        else if (selection == 'q' || selection == 'Q') {
            std::cout << "Goodbye" << std::endl;;
        }
        else {
            std::cout << "Unkown option, try again..." << std::endl;
        }

    } while (selection != 'q' && selection != 'Q');
    
    return 0;
}