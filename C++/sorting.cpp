#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <chrono>

void bubbleSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    if (arr.size() < 2) return;
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << " μs\n\n";
}

void insertionSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << " μs\n\n";
}

int main(void) {
    std::vector<int> arr;
    std::string input;
    int choice = 0;

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

    std::cout << "\n\nTo sort this list, we have 2 options:\n\n[1] Bubble Sort\n[2] Insertion Sort\n\nTake your pick (1-2): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        default:
            std::cout << "Invalid choice! Skipping sort.\n";
            break;
    }

    return 0;
}
