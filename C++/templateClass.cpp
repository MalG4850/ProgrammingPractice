#include <iostream>

//Declaring Template
template <typename T>
class Box {
    private:
        T value;

    public:
        Box(T v) { value = v; }
        void display() { std::cout << "Value: " << value << "\n\n"; }
};

int main(void) {

    //Declaring Box objects with various data types
    Box<std::string> B1("Hello, World!");
    Box<int> B2(58);

    //Using Display functions
    B1.display();
    B2.display();

    return 0;
}
