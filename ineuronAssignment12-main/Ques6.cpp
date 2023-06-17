#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to retain M nodes and delete the next N nodes in a linked list
void retainDelete(Node* head, int M, int N) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    int retainCount = 0;
    int deleteCount = 0;

    // Traverse the linked list
    while (current != nullptr) {
        retainCount = 0;
        deleteCount = 0;

        // Retain M nodes
        while (current != nullptr && retainCount < M) {
            previous = current;
            current = current->next;
            retainCount++;
        }

        // Delete N nodes
        while (current != nullptr && deleteCount < N) {
            Node* temp = current;
            current = current->next;
            delete temp;
            deleteCount++;
        }

        // Update the 'next' pointer of the previous node to skip the deleted nodes
        previous->next = current;
    }
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

    int M, N;
    cout << "Enter the values of M and N: ";
    cin >> M >> N;

    retainDelete(head, M, N);

    cout << "Linked list after retaining M nodes and deleting N nodes:" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the memory by deleting the linked list
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

