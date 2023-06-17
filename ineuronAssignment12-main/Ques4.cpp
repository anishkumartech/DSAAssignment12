#include <iostream>
#include <stack>

using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    Node* slowPtr = head;
    Node* fastPtr = head;

    // Find the middle node and move slowPtr to the second half
    stack<char> secondHalf;
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        secondHalf.push(slowPtr->data);
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Skip the middle node if the length is odd
    if (fastPtr != nullptr) {
        slowPtr = slowPtr->next;
    }

    // Compare the nodes of the first half with the reversed second half
    while (slowPtr != nullptr) {
        char top = secondHalf.top();
        secondHalf.pop();

        if (slowPtr->data != top) {
            return false;
        }

        slowPtr = slowPtr->next;
    }

    return true;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the characters of the linked list (enter '.' to stop):" << endl;

    char value;
    while (true) {
        cin >> value;
        if (value == '.') {
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

    bool isPalindromeResult = isPalindrome(head);

    if (isPalindromeResult) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

