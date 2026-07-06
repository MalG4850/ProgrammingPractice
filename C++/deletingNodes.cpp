#include <iostream>

class Node {
private:
    int data;
    Node* next;

public:
    Node(int val) : data(val), next(nullptr) {}

    friend Node* deleteNode(Node* head, int targetValue);

    void setNext(Node* nextNode) { this->next = nextNode; }
    int getData() { return data; }
    Node* getNext() { return next; }
};

// Returns the new head of the list (in case the head itself gets deleted!)
Node* deleteNode(Node* head, int targetValue) {
    if (head == nullptr) return nullptr;

    // Edge Case: What if the very first node (head) holds the target value?
    if (head->data == targetValue) {
        Node* temp = head->next;
        delete head;
        return temp; // The second node becomes the new head
    }

    Node* current = head;

    while(current -> next != nullptr) {
        if (current -> next -> data == targetValue) {
            Node* temp = current -> next;
            current -> next = current -> next -> next;
            delete temp;
            return head;
        } else {
            current = current -> next;
        }
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData() << " -> ";
        current = current->getNext();
    }
    std::cout << "nullptr\n";
}

int main(void) {
    Node* n1 = new Node(10);
        Node* n2 = new Node(20);
        Node* n3 = new Node(30);
        Node* n4 = new Node(40);

        n1->setNext(n2);
        n2->setNext(n3);
        n3->setNext(n4);

        Node* head = n1;
        std::cout << "Original List:\n";
        printList(head);
        std::cout << "\n";

        // ---- TEST 1: Delete from the middle (30) ----
        std::cout << "Deleting 30...\n";
        head = deleteNode(head, 30);
        printList(head); // Expected: 10 -> 20 -> 40 -> nullptr
        std::cout << "\n";

        // ---- TEST 2: Delete the end node (40) ----
        std::cout << "Deleting 40...\n";
        head = deleteNode(head, 40);
        printList(head); // Expected: 10 -> 20 -> nullptr
        std::cout << "\n";

        // ---- TEST 3: Delete the front head node (10) ----
        std::cout << "Deleting 10 (The Head)...\n";
        head = deleteNode(head, 10);
        printList(head); // Expected: 20 -> nullptr
        std::cout << "\n";

        // Clean up remaining allocated memory (only node 20 is left at this point)
        delete head;

    return 0;
}
