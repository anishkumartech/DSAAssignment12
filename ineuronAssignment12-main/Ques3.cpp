#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to find the Nth node from the end of the linked list
int findNthFromEnd(Node* head, int N) {
    if (head == nullptr || N <= 0) {
        return -1;
    }

    Node* currPtr = head;
    Node* prevPtr = head;

    // Move currPtr N nodes ahead
    for (int i = 0; i < N; i++) {
        if (currPtr == nullptr) {
            return -1; // Length of the linked list is less than N
        }
        currPtr = currPtr->next;
    }

    // Move both pointers until currPtr reaches the end
    while (currPtr != nullptr) {
        currPtr = currPtr->next;
        prevPtr = prevPtr->next;
    }

    return prevPtr->data;
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

    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int result = findNthFromEnd(head, N);

    if (result == -1) {
        cout << "Invalid input or N is greater than the length of the linked list." << endl;
    } else {
        cout << "The Nth node from the end is: " << result << endl;
    }

    return 0;
}

