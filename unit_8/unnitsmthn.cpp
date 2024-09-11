/*#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at a specific position
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = data;       // Assign data to the new node
    newNode->next = nullptr;    // Initialize next to null

    if (position == 1) { // Insertion at the beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head; // Temporary node to traverse the list

    // Traverse the list to find the position to insert
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) { // Invalid position (greater than the list length)
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }

    // Insertion at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;  // Initialize an empty list

    // Inserting elements in the linked list
    insertAtPosition(head, 10, 1); // Insert 10 at position 1
    insertAtPosition(head, 20, 2); // Insert 20 at position 2
    insertAtPosition(head, 30, 3); // Insert 30 at position 3
    insertAtPosition(head, 40, 2); // Insert 40 at position 2

    displayList(head);  // Display the list

    return 0;
}

##union of two sorted arrays

#include <iostream>
using namespace std;

void unionOfSortedArrays(int *arr1, int n, int *arr2, int m) {
    int *i = arr1;  // Pointer to the first element of arr1
    int *j = arr2;  // Pointer to the first element of arr2

    // Traverse both arrays
    while (i < arr1 + n && j < arr2 + m) {
        if (*i < *j) {
            cout << *i << " ";
            i++;
        } else if (*i > *j) {
            cout << *j << " ";
            j++;
        } else {
            cout << *i << " ";  // Print only one element when equal
            i++;
            j++;
        }
    }

    // Print remaining elements of arr1, if any
    while (i < arr1 + n) {
        cout << *i << " ";
        i++;
    }

    // Print remaining elements of arr2, if any
    while (j < arr2 + m) {
        cout << *j << " ";
        j++;
    }
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Union of two sorted arrays: ";
    unionOfSortedArrays(arr1, n, arr2, m);
    cout << endl;

    return 0;
}


*/