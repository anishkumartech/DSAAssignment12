#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to check if a linked list contains a loop
bool hasLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
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

    // Create a loop for testing (comment this section to test without a loop)
    tail->next = head;

    bool hasLoopResult = hasLoop(head);

    if (hasLoopResult) {
        cout << "The linked list contains a loop." << endl;
    } else {
        cout << "The linked list does not contain a loop." << endl;
    }

    return 0;
}

