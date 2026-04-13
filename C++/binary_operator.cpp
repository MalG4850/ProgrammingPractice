#include <iostream>

class Book {
    private:
        int pages;
        std::string title;

    public:
        Book(std::string t, int pg) {
            title = t;
            pages = pg;
        }
        Book operator +(Book& other) {
            std::string newTitle = this->title + "&" + other.title;
            int newPages = this->pages + other.pages;
            return Book(newTitle, newPages);
        }

        bool operator ==(Book& other) {
            if (this->pages == other.pages)
                return true;
            else return false;
        }
};

int main(void) {
    Book b1("C++ Basics", 200), b2("Advanced C++", 200);
    Book b3 = b1 + b2;
    bool y = (b1 == b2);
    std::cout << y;

    return 0;
}
