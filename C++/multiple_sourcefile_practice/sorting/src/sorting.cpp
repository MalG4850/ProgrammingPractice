#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "sorting.hpp"

namespace sortHelper {
    int partition(std::vector<int>& arr, int low, int high, long long& iterations, long long& swaps) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            iterations++;
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
                swaps++;
            }
        }
        std::swap(arr[i + 1], arr[high]);
        swaps++;
        return (i + 1);
    }

    void quickSortImpl(std::vector<int>& arr, int low, int high, long long& iterations, long long& swaps) {

        if (low < high) {
            int pi = partition(arr, low, high, iterations, swaps);
            quickSortImpl(arr, low, pi - 1, iterations, swaps);
            quickSortImpl(arr, pi + 1, high, iterations, swaps);
        }

    }
}

int getRandom() {
    return rand();
}

void bubbleSort(std::vector<int>& arr) {
    long long iterations = 0, swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    if (arr.size() < 2) return;
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            iterations++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                swaps++;
            }
        }
        if (!swapped) break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: \n\n";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << " μ sec" << "\nIterations: " << iterations << "\nSwaps: " << swaps << "\n\n";
}

void insertionSort(std::vector<int>& arr) {
    long long iterations = 0, swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            iterations++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        if (j >= 0) iterations++;
        arr[j + 1] = temp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: \n\n";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << " μ sec" << "\nIterations: " << iterations << "\nSwaps: " << swaps << "\n\n";
}

void quickSort(std::vector<int>& arr) {
    long long iterations = 0, swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    if (arr.empty()) return;

    sortHelper::quickSortImpl(arr, 0, arr.size() - 1, iterations, swaps);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: \n\n";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\nTime required: " << duration.count() << " μ sec" << "\nIterations: " << iterations << "\nSwaps: " << swaps << "\n\n";
}

void selectionSort(std::vector<int>& arr) {
    long long iterations = 0;
    long long swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    if (arr.size() >= 2) {
        for (int i = 0; i < arr.size() - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < arr.size(); j++) {
                iterations++; // Inner loop loop comparison
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(arr[i], arr[min_index]);
                swaps++;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nList sorting successful! Here is the output list: \n\n";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\nTime required: " << duration.count() << " μ sec" << "\nIterations: " << iterations << "\nSwaps: " << swaps << "\n\n";
}
