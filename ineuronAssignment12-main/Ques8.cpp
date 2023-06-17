#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* tortoise = head;
    Node* hare = head;

    while (hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        // If the tortoise and hare meet, the linked list is circular
        if (tortoise == hare) {
            return true;
        }
    }

    return false;
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

    // Make the linked list circular (for testing purposes)
    if (tail != nullptr) {
        tail->next = head;
    }

    bool isCircularList = isCircular(head);

    if (isCircularList) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    // Free the memory by deleting the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

