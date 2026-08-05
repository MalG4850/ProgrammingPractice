#include <iostream>
#include "sorting.hpp"
#include <vector>
#include <stdexcept>

int main(void) {
    std::vector<int> arr;
    std::string input;
    int choice = 0;
    char continuation = 'y';

    input:
        std::cout << "\nThis is a program to sort a list of numbers.\n\n";
        std::cout << "Enter numbers (enter 'q' to stop): ";

    while (std::cin >> input && input != "q") {
        try {
            int num = std::stoi(input);
            arr.push_back(num);
        } catch (const std::invalid_argument&) {
            std::cout << "\nError: Invalid input! Please enter a number or q to stop.\n\n";
        } catch (const std::out_of_range&) {
            std::cout << "\nError: Input number is too large!\n\n";
        }
    }

    std::cout << "\n\nNumber input successful! Here is the input list: ";
    for (int x : arr) {
        std::cout << x << " ";
    }

    std::cout << "\n\nTo sort this list, we have 4 options:\n\n[1] Bubble Sort\n[2] Insertion Sort\n[3] Quick Sort\n[4] Selection Sort\n[5] Exit\n\nTake your pick (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            goto input;
        case 2:
            insertionSort(arr);
            goto input;
        case 3:
            quickSort(arr);
            goto input;
        case 4:
            selectionSort(arr);
            goto input;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice! Skipping sort.\n";
            goto input;
    }

    std::cout << "Do you want to continue? [y/n]: ";
    std::cin >> continuation;
    if (continuation == 'y') goto input;
    else return 0;

    return 0;
}
