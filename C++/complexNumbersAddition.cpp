#include <iostream>

class Complex {

    public:
        double real, imag;
        Complex() {
            real = 0;
            imag = 0;
        }

        Complex(double r, double i) {
            real = r;
            imag = i;
        }
};

Complex add(Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

int main(void) {
    double r, i;
    std::cout << "\nThis is a program to add 2 complex numbers.";

    std::cout << "\n\nEnter the first number's real coefficient: ";
    std::cin >> r;
    std::cout << "\nEnter the first number's imaginary coefficient: ";
    std::cin >> i;

    Complex c1(r, i);


    r = 0;
    i = 0;

    std::cout << "\nEnter the second number's real coefficient: ";
    std::cin >> r;
    std::cout << "\nEnter the second number's imaginary coefficient: ";
    std::cin >> i;

    Complex c2(r, i);
    Complex c3 = add(c1, c2);

    std::cout << "\nThe addition of the 2 complex numbers is: " << c3.real << " + " << c3.imag << "i\n\n";

    return 0;
}
