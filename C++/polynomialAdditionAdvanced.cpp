#include <iostream>

typedef struct Polynomial {
    int exp, coeff;
} Polynomial;


int main(void) {

    int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;
    std::cout << "\nThis is a program to add 2 polynomials.\n\n";

    // Accepting Polynomial 1
    std::cout << "Enter the number of terms for Polynomial 1: ";
    std::cin >> n1;
    Polynomial p1[n1];

    for (i = 0; i < n1; i++) {

        std::cout << "\nEnter the exponent of term " << (i + 1) << ": ";
        std::cin >> p1[i].exp;

        std::cout << "\nEnter the coefficient of term " << (i + 1) << ": ";
        std::cin >> p1[i].coeff;

    }

    // Accepting Polynomial 2
    std::cout << "\nEnter the number of terms of Polynomial 2: ";
    std::cin >> n2;
    Polynomial p2[n2];

    for (j = 0; j < n2; j++) {

        std::cout << "\nEnter the exponent of term " << (j + 1) << ": ";
        std::cin >> p2[j].exp;

        std::cout << "\nEnter the coefficient of term " << (j + 1) << ": ";
        std::cin >> p2[j].coeff;

    }

    i = 0; j = 0;

    // Cleansing the input polynomials

    // Poly 1
    for (int i = 0; i < n1 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (p1[j].exp < p1[j + 1].exp) {
                std::swap(p1[j], p1[j + 1]);
            }
        }
    }

    i = 0; j = 0;

    for (int i = 0; i < n1 - 1; i++) {
            if (p1[i].exp == p1[i + 1].exp) {
                p1[i].coeff += p1[i + 1].coeff;
                p1[i + 1].coeff = 0;
                p1[i + 1].exp = -1;
                i--;
            }
    }

    i = 0; j = 0;

    // Poly 2
    for (int i = 0; i < n2 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (p2[j].exp < p2[j + 1].exp) {
                std::swap(p2[j], p2[j + 1]);
            }
        }
    }

    i = 0; j = 0;

    for (int i = 0; i < n2 - 1; i++) {
            if (p2[i].exp == p2[i + 1].exp) {
                p2[i].coeff += p2[i + 1].coeff;
                p2[i + 1].coeff = 0;
                p2[i + 1].exp = -1;
                i--;
            }
    }

    // Resultant Polynomial Declaration
    Polynomial result[n1 + n2];
    i = 0; j = 0;

    // Addition logic
    while (i < n1 && j < n2) {

        if (p1[i].exp == p2[j].exp) {

            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].exp = p1[i].exp;
            i++; j++; k++;

        } else if (p1[i].exp < p2[j].exp) {

            result[k].exp = p2[j].exp;
            result[k].coeff = p2[j].coeff;
            j++; k++;

        } else if (p1[i].exp > p2[j].exp) {

            result[k].exp = p1[i].exp;
            result[k].coeff = p1[i].coeff;
            i++; k++;

        }

    }

    // Scanning leftovers into the result
    while (i < n1) {
        result[k] = p1[i];
        i++; k++;
    }

    while (j < n2) {
        result[k] = p2[j];
        j++; k++;
    }

    int counter = 0;
    for (int i = 0; i < k; i++) {
        if (result[i].coeff == 0) counter++;
    }

    // Displaying the result
    if (counter == k) {
        std::cout << "\nThe resultant polynomial is 0.";
    } else {
        std::cout << "\nThe resultant polynomial is: ";
        for (int x = 0; x < k; x++) {
            if (result[x].coeff <= 0) {
                std::cout << "";
                continue;
            }
            else if (result[x].exp == 0) {
                std::cout << result[x].coeff << " ";
                continue;
            }
            else std::cout << result[x].coeff << "x^" << result[x].exp << " ";
        }
    }

    std::cout << "\n\n";

    return 0;

}
