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
    int ch;
    Node* head = new Node(11);
    Node* n1 = new Node(22);
    Node* n2 = new Node(33);
    Node* n3 = new Node(44);
    Node* temp = new Node(0);
    head -> setNext(n1);
    n1 -> setNext(n2);
    n2 -> setNext(n3);

    std::cout << "After where do you want to insert the new node? ";
    std::cin >> ch;

    Node* nn = new Node(55);

    temp = head;
    while(temp -> getData() != ch) {
        temp = temp -> next;
    }

    nn = temp -> next;
    temp -> setNext(nn);

    return 0;
}
