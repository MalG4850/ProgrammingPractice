#include <iostream>

class Class1 {
    public:
        void display() { std::cout << "Displaying from Class 1.\n\n"; }
};

class Class2 {
    public:
        void display() { std::cout << "Displaying from Class 2.\n\n"; }
};

class Derived: public Class1, public Class2 {};

int main(void) {
    Derived d1;

    //Display from Class 1
    d1.Class1::display();

    //Display from Class 2
    d1.Class2::display();
    return 0;
}
