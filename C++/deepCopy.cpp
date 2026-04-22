#include <algorithm>
#include <iostream>

class Buffer {
    public:
        int size;
        int* data;

        Buffer(int s) {
            data = new int[s];
            size = s;
        }

        Buffer(const Buffer& oldObj) {
            data = new int[oldObj.size];
            size = oldObj.size;
            std::copy_n(oldObj.data, oldObj.size, data);
        }

        ~Buffer() {
            delete [] data;
        }

        Buffer& operator =(const Buffer& other) {
            if(this != &other) {
                delete [] data;
                size = other.size;
                data = new int[size];
                std::copy_n(other.data, size, data);
            }

            return *this;
        }
};

int main(void) {
    Buffer b1(5);
        for (int i = 0; i < 5; i++) b1.data[i] = i * 10;

        Buffer b2 = b1;
        b1.data[0] = 999;

        std::cout << "b1[0]: " << b1.data[0] << std::endl;
        std::cout << "b2[0]: " << b2.data[0] << "\n\n";

        return 0;
}
