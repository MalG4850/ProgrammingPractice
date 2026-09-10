#include <iostream>

class Node {
    private:
        int data;

    public:
        Node* next;
        Node(int val): data(val), next(nullptr) {}

        friend void printList(Node* node);

        void setNext(Node* nextNode) {
            this -> next = nextNode;
        }

        int getData() {
            return data;
        }
};

void printList(Node* node) {
    while(node -> next != nullptr) {
        std::cout << node -> data << " ";
        node = node -> next;
    }
}

int main(void) {
    Node* head = new Node(11);
    Node* nn = new Node(55);
    Node* n1 = new Node(22);
    Node* n2 = new Node(33);
    Node* n3 = new Node(44);
    Node* temp = new Node(2);
    head -> setNext(n1);
    n1 -> setNext(n2);
    n2 -> setNext(n3);

    if (head == nullptr) head = nn;
    else {
        while(temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = nn;
    }

    printList(head);

    return 0;
}
