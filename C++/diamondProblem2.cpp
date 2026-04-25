#include <iostream>

class Person {
    protected:
        std::string name;
};

class Student: virtual public Person {};

class Employee: virtual public Person {};

class Intern: virtual public Employee, virtual public Student {
    public:
        Intern(std::string n) { name = n; }

        void displayName() { std::cout << "Name: " << name; }
};

int main(void) {
    Intern I1("Malhar");
    I1.displayName();
    return 0;
}
