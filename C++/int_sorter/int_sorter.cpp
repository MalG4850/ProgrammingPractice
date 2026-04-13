#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream intFile("integers.txt");
    std::ofstream evenFile("even.txt");
    std::ofstream oddFile("odd.txt");

    if (!intFile.is_open() || !evenFile.is_open() || !oddFile.is_open()) {
        std::cerr << "Error: Could not open one or more files.\n";
        return 1;
    }

    int n, count = 0;
    while (intFile >> n) {
        if (n % 2 == 0)
            evenFile << n << "\n";
        else oddFile << n << "\n";

        count++;
    }

    intFile.close();
    evenFile.close();
    oddFile.close();

    std::cout << "Sorting Complete.\n" << count << " numbers have been sorted.\n\n";

    return 0;
}
