#include <fstream>
#include <iostream>

int main() {
    char b = '#';
    std::fstream file("file_char.dat", std::ios::out | std::ios::binary);

    if (file) {
        file.write(&b, sizeof(char));
        file.close();
        std::cout << "Section 2: Wrote char successfully.\n";
    }

    char c = ' ';
    file.open("file_char.dat", std::ios::in | std::ios::binary);
    if (file) {
        file.read(&c, sizeof(char));
        file.close();
        std::cout << "Section 2: Read c = " << c << "\n\n";
    }
    return 0;
}
