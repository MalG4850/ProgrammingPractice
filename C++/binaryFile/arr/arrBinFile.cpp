#include <fstream>
#include <iostream>

int main() {
    int arr[] = {1, 1, 23, 4, 69, 482};
    std::fstream file("file_array.dat", std::ios::out | std::ios::binary);

    if (file) {
        file.write(reinterpret_cast<char*>(arr), sizeof(arr));
        file.close();
        std::cout << "Section 3: Wrote array successfully.\n";
    }

    int read_arr[6];
    file.open("file_array.dat", std::ios::in | std::ios::binary);
    if (file) {
        file.read(reinterpret_cast<char*>(read_arr), sizeof(read_arr));
        file.close();
        std::cout << "Array: ";
        for (int i : read_arr) std::cout << i << " ";
    }
    return 0;
}
