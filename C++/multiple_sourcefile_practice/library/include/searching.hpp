#pragma once
#include <vector>
#include <string>
class Book {
    private:
        std::string name, author, publisher;
        long long ISBN;

    public:
        Book(const std::string& n, const std::string& a, const std::string& p, const long long& i) : name(n), author(a), publisher(p), ISBN(i) {}

        std::string getName() const { return name; }
        std::string getPublisher() const { return publisher; }
        std::string getAuthor() const { return author; }
        long long getISBN() const { return ISBN; }
};

void searchByISBN(const std::vector<Book>& lib, int& start, int& end, long long& key);
void searchByAuthor(const std::vector<Book>& lib, int& start, int& end, std::string& key);
void showCostliest();
void showCheapest();
void displayBook();
