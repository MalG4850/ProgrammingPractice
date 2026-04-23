#include <iostream>

class InternalExam {

    protected:
        int internal_marks;

    public:

        void setMarks(int m) { internal_marks = m; }
        void showMarks() { std::cout << "Internal Marks: " << internal_marks << std::endl; }
};

class ExternalExam {

    protected:
        int external_marks;

    public:

        void setMarks(int m) { external_marks = m; }
        void showMarks() { std::cout << "External Marks: " << external_marks << std::endl; }
};

class FinalResult: public InternalExam, public ExternalExam {

    public:

        FinalResult(int i, int e) {
            internal_marks = i;
            external_marks = e;
        }

        void showMarks() { std::cout << "Final Result: " << internal_marks + external_marks << std::endl; }
};

int main(void) {
    int i, e;

    std::cout << "Enter Internal Marks: ";
    std::cin >> i;
    std::cout << "Enter External Marks: ";
    std::cin >> e;
    FinalResult f1(i, e);

    f1.showMarks();
    f1.InternalExam::showMarks();
    f1.ExternalExam::showMarks();

    return 0;
}
