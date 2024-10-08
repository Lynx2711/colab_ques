#include<iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

void insert(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteValue(Node* &head, int value) {
    if (head == nullptr) return; 
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    
    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    
    if (current != nullptr) {
        previous->next = current->next;
        delete current;
    }
}


void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, deleteVal;
   cout << "Enter the number of elements in the linked list: ";
    cin >> n;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(head, value);
    }
    cout << "Enter the value to delete: ";
    cin >> deleteVal;
    deleteValue(head, deleteVal);
    cout << "Updated linked list: ";
    display(head);

    return 0;
}
