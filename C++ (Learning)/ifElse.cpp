/* if (expr) {
        statement;
    }
    else if (expr) {
        statement;
    }
    else {
        statement;
    }
*/
#include <iostream>

int main() {
//    int num = 0;
//    const int min = 10;
//    const int max = 100;
//
//    std::cout << "Enter a number between " << min << " and " << max << ":";
//    std::cin >> num;

//    if (num >= 10) {
//        std::cout << "\n========================== IF statement 1 ==========================" << std::endl;
//        std::cout << num << " is greater than or equal to " << min << std::endl;
//
//        int diff = num - min;
//        std::cout << num << " is " << diff << " greater than " << min << std::endl;
//    }
//
//    if (num <= max) {
//        std::cout << "\n========================== IF statement 2 ==========================" << std::endl;
//        std::cout << num << " is less than or equal to " << max << std::endl;
//
//        int diff = max - num;
//        std::cout << num << " is " << diff << " less than " << max << std::endl;
//    }
//
//    if (num >= min && num <= max) {
//        std::cout << "\n========================== IF statement 3 ==========================" << std::endl;
//        std::cout << num << " is in range " << std::endl;
//    }

// Nested if statement
    int score = 0;
    std::cout << "Enter your exam score (0-100):";
    std::cin >> score;

    char letter_grade = 0;
    if (score >= 0 && score <= 100) {
        if (score >= 90){
            letter_grade = 'A';
        }
        else if (score >= 80) {
            letter_grade = 'B';
        }
        else if (score >= 70) {
            letter_grade = 'C';
        }
        else if (score >= 60) {
            letter_grade = 'D';
        }
        else {
            letter_grade ='F';
        }

        std::cout << "Your grade is " << letter_grade << std::endl;

        if (letter_grade == 'F') {
            std::cout << "Sorry, you must repeat this class." << std::endl;
        } else {
            std::cout << "Congrats!" << std::endl;
        }
    } else {
        std::cout << "Sorry, " << score << " is not in range." << std::endl;
    }
    return 0;
}