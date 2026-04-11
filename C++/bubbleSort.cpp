#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
        if (!swapped) break;
    }
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "\nUsage: " << argv[0] << " [textfile_name]" << "\n\n";
        return -1;
    }

    std::string filename = argv[1];
    std::vector<int> numbers;
    int temp;

    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        while(inputFile >> temp) { numbers.push_back(temp); }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file.";
        return 1;
    }

    bubbleSort(numbers);

    std::ofstream outputFile(filename);
    for (int num : numbers) { outputFile << num << "\n"; }
    outputFile.close();

    std::cout << "\nNumbers were sorted successfully!\n\n";

    return 0;
}
