#include <iostream>

template <typename T>
T greater(T a, T b) {
    return (a > b) ? a : b;
}

int main(void) {
    int num1[2];
    double num2[2];

    //Taking integers
    for (int i = 0; i < 2; i++) {
        std::cout << "\nEnter integer " << i+1 << ": ";
        std::cin >> num1[i];
    }

    //Taking doubles
    for (int i = 0; i < 2; i++) {
        std::cout << "\nEnter double " << i+1 << ": ";
        std::cin >> num2[i];
    }

    std::cout << "Greater int: " << greater<int>(num1[0], num1[1]);

    std::cout << "Greater int: " << greater<double>(num2[0], num2[1]);

    return 0;
}
