#include <iostream>

class Buffer {
    private:
        int size;
        int* ptr;

    public:
        Buffer(int s): size(s) {
            ptr = new int[s];
        }

        ~Buffer() { delete [] ptr; };

        void fillArray() {
            for (int i = 0; i < size; i++) {
                std::cout << "Enter the Element: ";
                std::cin >> ptr[i];
            }
        }

        void printArray() const {
            for (int i = 0; i < size; i++) { std::cout << ptr[i] << " "; }
            std::cout << std::endl;
        }
};

int main(void) {
    Buffer B1(3);
    B1.fillArray();
    B1.printArray();

    return 0;
}
