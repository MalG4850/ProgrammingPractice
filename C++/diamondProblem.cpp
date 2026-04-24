#include <iostream>

class Person {
    public:
        std::string name;
};

class Teacher: virtual public Person {};

class Student: virtual public Person {};

class TeachingAssistant: public Teacher, public Student {};

int main(void) {
    std::string n;
    TeachingAssistant t1;
    std::cout << "Enter the TA's Name: ";
    std::cin >> t1.name;

    return 0;
}
