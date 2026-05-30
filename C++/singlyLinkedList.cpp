/* Imagine you are given the head pointer of a singly linked list.
Your task is to write a function that travels down the list and
counts the total number of nodes inside it (calculating its length). */

#include <iostream>

class Node {
    private:
        int data;
        Node* next;

    public:
        Node(int val): data(val), next(nullptr) {}

        friend int getListLength(Node* n);

        void setNext(Node* nextNode) {
            this -> next = nextNode;
        }
};

int getListLength(Node* head) {
    int len = 0;
    Node* current = head;

    while(current != nullptr) {
        len++;
        current = current -> next;
    }

    return len;
}

int main(void) {
    Node* firstNode  = new Node(10);
    Node* secondNode = new Node(20);
    Node* thirdNode  = new Node(30);

    firstNode->setNext(secondNode);
    secondNode->setNext(thirdNode);

    Node* head = firstNode;
    int totalNodes = getListLength(head);
    std::cout << "The total number of nodes in the linked list is: " << totalNodes << "\n\n";

    delete firstNode;
    delete secondNode;
    delete thirdNode;

    return 0;
}
