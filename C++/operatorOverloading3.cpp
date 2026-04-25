#include <iostream>

class Complex {
    private:
        double real, imag;
    public:
        Complex() {};
        Complex(double r, double i) {
            real = r;
            imag = i;
        }
        friend Complex operator + (Complex& a, Complex& b);
        friend std::ostream& operator<< (std::ostream& out, Complex& c);
};

    Complex operator + (Complex& a, Complex& b) {
        Complex c;
        c.real = a.real + b.real;
        c.imag = a.imag + b.imag;
        return c;
    }

    std::ostream& operator<< (std::ostream& out, Complex& c) {
        out << c.real << " + " << c.imag << "i\n\n";
        return out;
    }

int main(void) {
    double r[2], i[2];
    for (int j = 0; j < 2; j++) {
        std::cout << "Enter the real part of complex no. " << j+1 << ": ";
        std::cin >> r[j];
        std::cout << "Enter the imaginary part of complex no. " << j+1 << ": ";
        std::cin >> i[j];
    }
    Complex c1(r[0], i[0]), c2(r[1], i[1]);
    Complex c3 = c1 + c2;
    std::cout << c3;
    return 0;
}
