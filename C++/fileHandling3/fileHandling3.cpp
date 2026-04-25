#include <fstream>
#include <iostream>
#include <string>


int main(void) {
    std::string s;
    std::ofstream dataFile("data.txt");
    if(dataFile) dataFile << "Hello World!";
    else std::cerr << "Error: Could not open file.\n\n";
    dataFile.close();

    std::ifstream file("data.txt");
    if(file) {
        while (std::getline(file, s)) {
            std::cout << s << std::endl;
        }
    }
    else std::cerr << "Error: Could not open file.\n\n";

    return 0;
}
