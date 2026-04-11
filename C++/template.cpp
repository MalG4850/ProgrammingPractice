#include <iostream>

template <typename T>
T add(T a, T b) {
    return a+b;
}

int main(void) {

    double num1, num2;
    std::cout << "This is a program to add 2 numbers, but using templates.\n\n";
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    std::cout << "Answer: " << add<double>(num1, num2) << std::endl;

    return 0;
}
