#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to remove the loop from a linked list
void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;

    // Find if a loop exists
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            break; // Loop found
        }
    }

    if (slowPtr != fastPtr) {
        return; // No loop present
    }

    // Move slowPtr to the head and keep fastPtr at the meeting point
    slowPtr = head;
    while (slowPtr->next != fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    // Find the previous node of the start node of the loop
    fastPtr->next = nullptr;
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
    int x;
    cout << "Enter the position of the node to form the loop (0 for no loop): ";
    cin >> x;

    if (x > 0) {
        Node* curr = head;
        Node* loopNode = nullptr;

        int count = 1;
        while (curr->next != nullptr) {
            if (count == x) {
                loopNode = curr;
            }
            curr = curr->next;
            count++;
        }

        curr->next = loopNode; // Form the loop
    }
    // End of loop creation

    removeLoop(head);

    cout << "Linked list after removing the loop:" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
