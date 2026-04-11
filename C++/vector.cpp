#include <iostream>
#include <vector>

int main(void) {
    std::vector<double> numbers = {};
    char ans = 'n';
    double input;

    do {
        std::cout << "Do you want to add a number? [y/n]: ";
        std::cin >> ans;
        if (ans == 'y') {
            std::cout << "\nEnter the number: ";
            std::cin >> input;
            numbers.push_back(input);
            continue;
        }
        else {break;}
    } while (true);

    std::cout << "The list goes as follows: \n";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
