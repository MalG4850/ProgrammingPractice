#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "searching.hpp"

int main(void) {
    std::cout << "\nLibrary Search Engine v0.1\n\n";

    std::vector<Book> library = {
            {"The Alchemist", "Paulo Coelho", "HarperTorch", 9780061122415},
            {"The Room on the Roof", "Ruskin Bond", "Penguin Books", 9780140135961},
            {"India Unbound", "Gurcharan Das", "Penguin Books", 9780141001128},
            {"The Argumentative Indian", "Amartya Sen", "Penguin Books", 9780141021188},
            {"Ignited Minds", "A.P.J. Abdul Kalam", "Penguin Books", 9780143029823},
            {"The Guide", "R.K. Narayan", "Penguin Books", 9780143039645},
            {"Jaya: An Illustrated Retelling of the Mahabharata", "Devdutt Pattanaik", "Penguin", 9780143104257},
            {"सीता: An Illustrated Retelling of the Ramayana", "Devdutt Pattanaik", "Penguin", 9780143425601},
            {"The Discovery of India", "Jawaharlal Nehru", "Signet Press", 9780195623597},
            {"Midnight's Children", "Salman Rushdie", "Jonathan Cape", 9780224018870},
            {"The Inheritance of Loss", "Kiran Desai", "Hamish Hamilton", 9780241143278},
            {"The Palace of Illusions", "Chitra Banerjee Divakaruni", "Pan Macmillan", 9780330455725},
            {"India After Gandhi", "Ramachandra Guha", "Macmillan", 9780330505567},
            {"Maximum City: Bombay Lost and Found", "Suketu Mehta", "Knopf", 9780375403729},
            {"A Suitable Boy", "Vikram Seth", "Faber & Faber", 9780571165131},
            {"The God of Small Things", "Arundhati Roy", "IndiaInk", 9780670873340},
            {"Train to Pakistan", "Khushwant Singh", "Grove Press", 9780802132215},
            {"The White Tiger", "Aravind Adiga", "Free Press", 9781416562597},
            {"The Anarchy: The East India Company, Corporate Violence, and the Pillage of an Empire", "William Dalrymple", "Bloomsbury", 9781408864371},
            {"To All the Boys I've Loved Before", "Jenny Han", "Simon & Schuster", 9781442426702},
            {"Godan", "Munshi Premchand", "Rajkamal Prakashan", 9788126709120},
            {"Five Point Someone", "Chetan Bhagat", "Rupa Publications", 9788129104593},
            {"One Night @ the Call Center", "Chetan Bhagat", "Rupa Publications", 9788129108133},
            {"The 3 Mistakes of My Life", "Chetan Bhagat", "Rupa Publications", 9788129115224},
            {"2 States", "Chetan Bhagat", "Rupa Publications", 9788129115309},
            {"Revolution 2020", "Chetan Bhagat", "Rupa Publications", 9788129118539},
            {"Half Girlfriend", "Chetan Bhagat", "Rupa Publications", 9788129135728},
            {"Wings of Fire: An Autobiography", "A.P.J. Abdul Kalam", "Universities Press", 9788173711466},
            {"Malgudi Days", "R.K. Narayan", "Indian Thought Publications", 9788185986159},
            {"Dr. Babasaheb Ambedkar: Writings and Speeches", "B.R. Ambedkar", "Government of Maharashtra", 9789351090649},
            {"The Immortals of Meluha", "Amish Tripathi", "Westland", 9789380658742},
            {"The Secret of the Nagas", "Amish Tripathi", "Westland", 9789380658797},
            {"The Oath of the Vayuputras", "Amish Tripathi", "Westland", 9789382618782},
            {"An Era of Darkness: The British Empire in India", "Shashi Tharoor", "Aleph Book Company", 9789384067552},
            {"Bhagavad Gita As It Is", "A.C. Bhaktivedanta Swami Prabhupada", "The Bhaktivedanta Book Trust", 9789384564341},
            {"Ram: Scion of Ikshvaku", "Amish Tripathi", "Westland", 9789385990064},
            {"Sita: Warrior of Mithila", "Amish Tripathi", "Westland", 9789386224886},
            {"Raavana: Enemy of Aryavarta", "Amish Tripathi", "Westland", 9789387578383},
            {"Girl in Room 105", "Chetan Bhagat", "Westland", 9789387578635}
        };

    int start = 0;
    int end = library.size() - 1;
    long long isbnKey = 0;
    std::string authorKey;
    short choice;

    std::cout << "How do you want to search a book?\n\n[1] By ISBN\n[2] By Author\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    try{
        if (choice == 1) {
            std::cout << "\nEnter the ISBN: ";
            std::cin >> isbnKey;
            std::cout << "Searching for ISBN: " << isbnKey << "\n";
            searchByISBN(library, start, end, isbnKey);
        } else if (choice == 2) {
            std::cout << "\nEnter the name of Author: ";
            std::cin.ignore();
            std::getline(std::cin, authorKey);
            std::cout << "\nSearching for Author: " << authorKey << "\n";
            searchByAuthor(library, start, end, authorKey);
        } else throw std::invalid_argument("");
    } catch (const std::exception& e) { std::cerr << "Error: Invalid choice!\n\n"; }

    return 0;
}
