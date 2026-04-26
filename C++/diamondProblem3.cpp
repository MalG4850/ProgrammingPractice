#include <iostream>

class Person {
    protected:
        std::string name;

    public:
        Person(std::string n): name(n) {}
};

class Faculty: virtual public Person {
    protected:
        std::string department;

    public:
        Faculty(std::string n, std::string d): Person(n), department(d) {}
};

class Student: virtual public Person {
    protected:
        float GPA;

    public:
        Student(std::string n, float g): Person(n), GPA(g) {}
};

class TeachingAssistant: virtual public Faculty, virtual public Student {
    public:
        TeachingAssistant(std::string n, std::string d, float g): Person(n), Faculty(n, d), Student(n,g) {}

        void display() const {
            std::cout << "Name: " << name << "\nDepartment: " << department << "\nGPA: " << GPA;
        }
};

int main(void) {
    TeachingAssistant T1("Malhar", "Engineering and Technology", 9.1);
    T1.display();

    return 0;
}
