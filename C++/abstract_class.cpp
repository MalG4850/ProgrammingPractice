#include <iostream>

namespace AnimalShelter {
    class Animal {
        public:
            virtual void sound() = 0;

            virtual ~Animal() {};
    };

    class Dog final: public Animal {
        public:
            void sound() override {
                std::cout << "\n*Barking noises*\n\n";
            }
    };
}

int main(void) {
    AnimalShelter::Dog d;
    AnimalShelter::Animal* a = &d;
    a -> sound();

    return 0;
}
