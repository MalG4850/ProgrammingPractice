#include <iostream>

int main(void) {
    double a, b;
    division:
        try{
            std::cout << "This is a program to divide 2 numbers.\n\n";
            std::cout << "Enter the dividend: ";
            std::cin >> a;
            std::cout << "\nEnter the Divisor: ";
            std::cin >> b;
            if (b == 0) throw b;
            else {
                std::cout << "The quotient is: " << a/b;
            }
        }
        catch (double b) {
            std::cerr << "Error: you cannot divide by zero!\n\n";
            goto division;
        }
        catch (...) {
            std::cerr << "A generic error occurred.\n\n";
            goto division;
        }

    return 0;
}
