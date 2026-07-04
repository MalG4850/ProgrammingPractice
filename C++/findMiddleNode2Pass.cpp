#include <iostream>

class Node {
    private:
        int data;
        Node* next;

    public:
        Node(int val): data(val), next(nullptr) {}

        friend int findMiddleNode2Pass(Node* head) {
            // Logic
            if (head == nullptr) return -1;

            int totalNodes = 0;
            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast -> next != nullptr) {
                slow = slow -> next;
                fast = fast -> next -> next;
            }

            return slow -> data;
        }

        void setNext(Node* nextNode) {
            this -> next = nextNode;
        }
};

int main(void) {

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1 -> setNext(n2);
    n2 -> setNext(n3);
    n3 -> setNext(n4);
    n4 -> setNext(n5);

    std::cout << "\nThe middle node is: " << findMiddleNode2Pass(n1) << "\n\n";

    delete n1; delete n2; delete n3; delete n4; delete n5;

    return 0;
}
