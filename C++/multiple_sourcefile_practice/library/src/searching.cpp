#include <iostream>
#include "searching.hpp"
#include <vector>

void displayBook(const Book& b) {
    std::cout << "\n========== Book Info ==========\n\n";
    std::cout << "Name: " << b.getName();
    std::cout << "\nAuthor: " << b.getAuthor();
    std::cout << "\nPublisher: " << b.getPublisher();
    std::cout << "\nISBN: " << b.getISBN() << "\n\n===============================\n\n";
}

void searchByISBN(const std::vector<Book>& lib, int& start, int& end, long long& key) {
    while (start <= end) {
            int mid = start + (end - start)/2;
        if (lib[mid].getISBN() == key) {
            displayBook(lib[mid]);
            break;
        } else if (lib[mid].getISBN() < key) start = mid + 1; // start goes to index of temp
        else if (lib[mid].getISBN() > key) end = mid - 1; // end goes to index of temp
    }
}

void searchByAuthor(const std::vector<Book>& lib, int& start, int& end, std::string& key) {
    for (int i = 0; i < lib.size(); i++) {
        if (lib[i].getAuthor() == key) displayBook(lib[i]);
        else continue;
    }
}
