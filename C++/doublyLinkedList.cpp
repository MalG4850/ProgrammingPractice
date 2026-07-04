// Imagine that you are building a routing engine for a web browser's forward/backward system.
// When a user visits a new page after clicking "Back" a few times, any forward history (the alternate future) must be cleared out
// to prevent memory leaks, and the new page is attached.
// When a user clicks "Back", your tracking pointer simply steps backward through the 'prev' pointers.


#include <iostream>

class Node {
    private:
        std::string url;
        Node* prev;
        Node* next;

    public:
        Node(std::string val): url(val), next(nullptr), prev(nullptr) {}

        friend class BrowserHistory;
};

class BrowserHistory {
    private:
        Node* current;

    public:
        BrowserHistory(std::string homepage) {
            current = new Node("homepage");
        }

        ~BrowserHistory() {
            while (current -> prev != nullptr) { current = current -> prev; }
            while (current != nullptr) {
                Node* nextNode = current -> next;
                delete current;
                current = nextNode;
            }
        }

        void visitPage(std::string newURL) {
            // Logic to destroy forward chain is user goes back and forward again.
            Node* forwardNode = current -> next;
            while (forwardNode != nullptr) {
                Node* nextToDelete = forwardNode -> next;
                delete forwardNode;
                forwardNode = nextToDelete;
            }

            // New node for a new page.
            Node* newPage = new Node(newURL);
            current -> next = newPage;
            newPage -> prev = current;

            current = newPage;
        }

        void back(int steps) {
            for (int i = 0; i < steps; i++) {
                if (current -> prev == nullptr) break;
            }
            current = current -> prev;
        }

        void showCurrentPage() {
            std::cout << "\nCurrently viewing: " << current -> url << "\n\n";
        }
};

int main(void) {
    BrowserHistory browser("google.com");
    browser.showCurrentPage();

    browser.visitPage("github.com");
    browser.visitPage("youtube.com");
    browser.visitPage("codeberg.org");

    std::cout << "Going back (back button clicked action)\n\n";
    browser.back(1);
    browser.showCurrentPage();

    browser.visitPage("stackoverflow.com");
    std::cout << "Visitin StackOverflow\n\n";
    browser.visitPage("stackoverflow.com");
    browser.showCurrentPage();

    return 0;
}
