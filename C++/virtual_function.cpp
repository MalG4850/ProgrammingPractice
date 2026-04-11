#include <iostream>

class Animal {
    public:
        virtual void sound() {
            std::cout << "\n*Animal sounds*\n\n";
        }

        virtual ~Animal() {}
};

class Dog: public Animal {
    public:
        void sound() override {
            std::cout << "\n*Barking sound*\n\n";
        }
};

int main(void) {
    Dog d;
    Animal* a = &d;
    a -> sound();
    // we can also use a.sound();

    return 0;
}
