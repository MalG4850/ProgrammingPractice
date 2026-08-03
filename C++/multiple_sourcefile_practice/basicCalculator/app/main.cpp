#include <bits/stdc++.h>
#include "add.hpp"
#include "subtract.hpp"
#include "divide.hpp"
#include "multiply.hpp"

void getNumbers(int& a, int& b) {
    std::printf("\nEnter the first integer: ");
    std::scanf("%d", &a);
    std::printf("\nEnter the second integer: ");
    std::scanf("%d", &b);
}

int main(void) {
    int choice, a = 0, b = 0;
    std::printf("\nThis is a program to calculate the basic operations of 2 integers.\n\n");
    input:
        std::printf("========Operations Menu========\n\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n[0] Exit\n\nEnter your choice: ");
        std::scanf("%d", &choice);

    if (choice == 0) return 0;
    getNumbers(a, b);
    switch (choice) {
        case 1:
            std::printf("\n\n%d + %d = %d\n\n", a, b, add(a, b));
            break;
        case 2:
            std::printf("\n\n%d - %d = %d\n\n", a, b, subtract(a, b));
            break;
        case 3:
            std::printf("\n\n%d × %d = %d\n\n", a, b, multiply(a, b));
            break;
        case 4:
            if (b != 0) std::printf("\n\n%d ÷ %d = %d\n\n", a, b, divide(a, b));
            else std::printf("Division by zero is undefined.\n\n");
            break;
        default:
            std::printf("\n\nError: Invalid Choice!\n\n");
            goto input;
        }

    return 0;
}
