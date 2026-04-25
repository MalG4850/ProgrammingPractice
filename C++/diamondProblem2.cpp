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
    std::string n;
    std::cout << "Enter the name of the Intern: ";
    std::cin >> n;
    Intern I1(n);
    I1.displayName();
    return 0;
}
