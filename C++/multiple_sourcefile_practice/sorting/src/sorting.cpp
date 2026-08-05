#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include "sorting.hpp"

namespace sortHelper {
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSortImpl(std::vector<int>& arr, int low, int high) {

        if (low < high) {
            int pi = partition(arr, low, high);
            quickSortImpl(arr, low, pi - 1);
            quickSortImpl(arr, pi + 1, high);
        }

    }
}

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
    std::cout << "\nTime required: " << duration.count() << "\n\n";
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
    std::cout << "\nTime required: " << duration.count() << "\n\n";
}

void quickSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    if (arr.empty()) return;

    sortHelper::quickSortImpl(arr, 0, arr.size() - 1);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << "\n\n";

}

void selectionSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1;j < arr.size() ; j++) {
            if (arr[j] < arr[min_index]) std::swap(arr[i], arr[j]);
        }
        std::swap(arr[min_index], arr[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << "\n\n";
}
