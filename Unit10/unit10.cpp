#include <iostream>
using namespace std;

// Node class representing each element in the list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert nodes into the linked list
void insert(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;  // First node
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;  // Append to the end of the list
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl; //print it outtt
}

// Function to delete the middle node from the linked list
void deleteMiddle(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        // List is empty or has only one element
        delete head;
        head = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    // Use the slow and fast pointer approach
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If there is a previous node, update its next pointer
    if (prev != nullptr) {
        prev->next = slow->next;
    }
    
    delete slow;  // Delete the middle node
}

int main() {
    int n, data;
    Node* head = nullptr;

    // Input number of elements in the list
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    // Input elements of the linked list
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(head, data);  // Insert each element into the linked list
    }

    // Print the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Delete the middle node
    deleteMiddle(head);

    // Print the updated linked list
    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}


/*
nothing to see here
*/