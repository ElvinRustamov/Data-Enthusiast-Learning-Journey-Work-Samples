// Solving factorial with using recursion

// factorial(n) = n × factorial(n – 1)

#include <iostream>

int factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n = 5;
    int answer = factorial(n);
    std::cout << n << " factorial is " << answer << std::endl;
    return 0;
}