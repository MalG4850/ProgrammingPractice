#include <fstream>
#include <iostream>

int main() {
    unsigned short int x = 8675;
    std::fstream file("shortIntFile.dat", std::ios::out | std::ios::binary);

    if (file) {
        file.write(reinterpret_cast<char*>(&x), sizeof(x));
        file.close();
        std::cout << "Section 1: Wrote short successfully.\n";
    }

    unsigned short int y = 0;
    file.open("file.dat", std::ios::in | std::ios::binary);
    if (file) {
        file.read(reinterpret_cast<char*>(&y), sizeof(y));
        file.close();
        std::cout << "Section 1: Read y = " << y << "\n\n";
    }
    return 0;
}
