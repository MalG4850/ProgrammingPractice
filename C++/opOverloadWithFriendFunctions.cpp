#include <iostream>

class Student{
    private:
        std::string name;
        int rollNo;

    public:
        Student() = default;

        Student(std::string n, int r) {
            name = n;
            rollNo = r;
        }

        friend std::ostream& operator <<(std::ostream& out, const Student& S);
        friend std::istream& operator >>(std::istream& in, Student& S);
};

std::ostream& operator <<(std::ostream& out, const Student& S) {
    out << "Student: " << S.name << "\nID: " << S.rollNo;
    return out;
}

std::istream& operator >>(std::istream& in, Student& S) {
    std::cout << "Enter the Name: ";
    in >> S.name;
    std::cout << "\nEnter the ID: ";
    in >> S.rollNo;

    return in;
}

int main(void) {
    Student s1;
    std::cin >> s1;
    std::cout << s1;

    return 0;
}
