#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete the middle node(s) of a linked list
Node* deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;
    Node* prevPtr = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
    }

    // If the number of nodes is even, move slowPtr one more step
    if (fastPtr == nullptr) {
        slowPtr = slowPtr->next;
    }

    // Delete the middle node(s)
    prevPtr->next = slowPtr->next;
    slowPtr->next = nullptr;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the elements of the linked list (enter -1 to stop):" << endl;

    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete the middle node(s)
    head = deleteMiddle(head);

    cout << "Modified linked list: ";
    printList(head);

    return 0;
}

