#include <iostream>

class RepCounter {
    private:
        int count;

    public:
        RepCounter() { count = 0; }
        void operator ++() { count++; }
        void operator -() { count = 0; }
        void display() { std::cout << "Count: " << count << std::endl; }
};

int main(void) {
    RepCounter c1;
    ++c1;
    c1.display();
    -c1;
    c1.display();

    return 0;
}
