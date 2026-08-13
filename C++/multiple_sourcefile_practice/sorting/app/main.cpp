#include <iostream>
#include "sorting.hpp"
#include <vector>
#include <stdexcept>

int main(void) {
    std::vector<int> arr;
    std::string input;
    short int choice = 0;
    char continuation = 'y';

    input:
        std::cout << "\nThis is a program to sort a list of numbers.\n\n";
        std::cout << "[1] Custom Entry\n[2] Random Set\n\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
    
    if (choice == 1) {
        choice = 0;
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
    } else if (choice == 2) {
        choice = 0;
        choiceMaker:
            std::cout << "\n\nHow many numbers in the random set?\n\n[1] 100\n[2] 500\n[3] 1000\n[3] 5000\n\nEnter your choice: ";
            std::cin >> choice;
        switch (choice) {
            case 1:
                for (int i = 0; i < 100; i++) arr.push_back(getRandom());
                break;
            case 2:
                for (int i = 0; i < 500; i++) arr.push_back(getRandom());
                break;
            case 3:
                for (int i = 0; i < 1000; i++) arr.push_back(getRandom());
                break;
            case 4:
                for (int i = 0; i < 5000; i++) arr.push_back(getRandom());
                break;
            default:
                std::cout << "Error: Invalid choice!\n\n";
                goto choiceMaker;
        }
    }
    choice = 0;

    std::cout << "\n\nTo sort this list, we have 4 options:\n\n[1] Bubble Sort\n[2] Insertion Sort\n[3] Quick Sort\n[4] Selection Sort\n[5] Exit\n\nTake your pick (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            quickSort(arr);
            break;
        case 4:
            selectionSort(arr);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice! Skipping sort.\n";
            goto input;
    }

    std::cout << "Do you want to continue? [y/n]: ";
    std::cin >> continuation;
    if (continuation == 'y') goto input;

    return 0;
}
