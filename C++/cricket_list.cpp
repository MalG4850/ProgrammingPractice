#include <iostream>
#include <limits>

struct Node {
    int id;
    int age;
    std::string name;
    std::string mobile;
    Node* next;
    Node(int i, const std::string& n, const std::string& m, int a)
        : id(i), age(a), name(n), mobile(m), next(nullptr) {}
};

Node* head = nullptr;

void addPlayer(void) {
    int id, age;
    std::string name, mob;
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Mobile: ";
    std::cin >> mob;
    std::cout << "Age: ";
    std::cin >> age;

    Node* n = new Node(id, name, mob, age);
    n->next = head;
    head = n;
    std::cout << "Player added.\n";
}

void deletePlayer(void) {
    int id;
    std::cout << "Enter ID to delete: ";
    std::cin >> id;
    Node* cur = head;
    Node* prev = nullptr;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        std::cout << "Player not found.\n";
        return;
    }
    if (prev) prev->next = cur->next;
    else head = cur->next;
    delete cur;
    std::cout << "Player deleted.\n";
}

void displayAll(void) {
    if (!head) {
        std::cout << "List empty.\n";
        return;
    }
    for (Node* p = head; p; p = p->next) {
        std::cout << "ID:" << p->id
                  << "  Name:" << p->name
                  << "  Mobile:" << p->mobile
                  << "  Age:" << p->age << '\n';
    }
}

void searchByName(void) {
    std::string s;
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    bool found = false;
    for (Node* p = head; p; p = p->next) {
        if (p->name == s) {
            std::cout << "ID:" << p->id
                      << "  Mobile:" << p->mobile
                      << "  Age:" << p->age << '\n';
            found = true;
        }
    }
    if (!found) std::cout << "No player with that name.\n";
}

void updateMobile(void) {
    int id;
    std::string mob;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "New mobile: ";
    std::cin >> mob;
    for (Node* p = head; p; p = p->next) {
        if (p->id == id) {
            p->mobile = mob;
            std::cout << "Mobile updated.\n";
            return;
        }
    }
    std::cout << "Player not found.\n";
}

int main(void) {
    int choice;
    while (true) {
        std::cout << "\n1.Add 2.Delete 3.Display 4.Search 5.Update 6.Exit\nChoice: ";
        if (!(std::cin >> choice)) break;
        switch (choice) {
            case 1: addPlayer(); break;
            case 2: deletePlayer(); break;
            case 3: displayAll(); break;
            case 4: searchByName(); break;
            case 5: updateMobile(); break;
            case 6: return 0;
            default: std::cout << "Invalid.\n";
        }
    }
    return 0;
}
