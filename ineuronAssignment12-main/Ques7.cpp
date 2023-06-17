
#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert nodes from the second list into alternate positions of the first list
void insertAlternate(Node* first, Node* second) {
    if (first == nullptr || second == nullptr) {
        return;
    }

    Node* firstCurrent = first;
    Node* secondCurrent = second;
    Node* firstNext = nullptr;

    while (firstCurrent != nullptr && secondCurrent != nullptr) {
        firstNext = firstCurrent->next; // Save the next node in the first list

        // Make the current node of the second list the next node of the first list
        firstCurrent->next = secondCurrent;
        secondCurrent = secondCurrent->next;

        // Connect the next node of the first list
        firstCurrent->next->next = firstNext;

        firstCurrent = firstNext; // Move to the next position in the first list
    }

    // If there are remaining nodes in the second list, append them at the end of the first list
    if (secondCurrent != nullptr) {
        firstCurrent->next = secondCurrent;
    }

    // Empty the second list
    second = nullptr;
}

int main() {
    Node* firstHead = nullptr;
    Node* firstTail = nullptr;

    Node* secondHead = nullptr;
    Node* secondTail = nullptr;

    cout << "Enter the elements of the first list (enter -1 to stop):" << endl;

    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (firstHead == nullptr) {
            firstHead = newNode;
            firstTail = newNode;
        } else {
            firstTail->next = newNode;
            firstTail = newNode;
        }
    }

    cout << "Enter the elements of the second list (enter -1 to stop):" << endl;

    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (secondHead == nullptr) {
            secondHead = newNode;
            secondTail = newNode;
        } else {
            secondTail->next = newNode;
            secondTail = newNode;
        }
    }

    insertAlternate(firstHead, secondHead);

    cout << "First list after inserting nodes from the second list:" << endl;
    Node* current = firstHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Second list after inserting into the first list:" << endl;
    current = secondHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the memory by deleting the linked lists
    current = firstHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    current = secondHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
