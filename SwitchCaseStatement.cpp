// Switch Case Statement

#include <iostream>

int main() {
    char letter_grade = 0;
    std::cout << "Enter the letter grade you expect on the exam:";
    std::cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A':
            std::cout << "You need a 90 or above, study hard!" << std::endl;
            break;
        case 'b':
        case 'B':
            std::cout << "You need 80-89 for a B, go study!" << std::endl;
            break;
        case 'c':
        case 'C':
            std::cout << "You need 70-79 for a C" << std::endl;
            break;
        case 'd':
        case 'D':
            std::cout << "You should strive for better grade. All you need is 60-69.";
            break;
        case 'f':
        case 'F':
        {
         char confirm = 0;
         std::cout << "Are you sure (Y/N):";
         std::cin >> confirm;

         if (confirm == 'y' || confirm == 'Y') {
             std::cout << "Okay, I guess you don't want to study." << std::endl;
         } else if (confirm == 'n' || confirm == 'N') {
             std::cout << "Good, go study" << std::endl;
         }
         else {
             std::cout << "Error.";
         }
        break;
        }
        default:
            std::cout << "Sorry, not a valid grade" << std::endl;
    }
    return 0;
}