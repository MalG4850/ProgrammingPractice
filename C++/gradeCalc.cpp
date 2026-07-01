#include <iostream>

float avgCalc() {
    float s1, s2, s3;
    std::cout << "Enter the marks of the first subject (out of 100): ";
    std::cin >> s1;

    std::cout << "\nEnter the marks of the second subject (out of 100): ";
    std::cin >> s2;

    std::cout << "\nEnter the marks of the third subject (out of 100): ";
    std::cin >> s3;

    return (s1 + s2 + s3)/3;
}

int main(void) {
    int num;
    float a = 0, a_buffer = 0, topper = 0;
    std::cout << "\nThis is a program to calculate the 3-subject grade average.\n\n";
    std::cout << "Enter the number of students: ";
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        std::cout << "\n\nFor student " << i+1 << "\n\n";
        a_buffer = avgCalc();
        std::cout << "\nThe average is: " << a_buffer << "%";

        if (a_buffer <= 0.4) {
            std::cout << "\n\nResult: Fail\n";
        } else { std::cout << "\n\nResult: Pass\n"; }

        if (a_buffer > a) {
            a = a_buffer;
            topper++;
        } else { continue; }
    }

    std::cout << "\nThe topper of the given group is: Student entry " << topper << " and their average is " << a << "%.\n\n\n";

    return 0;
}
