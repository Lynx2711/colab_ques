/* Read  the list of initial lines and then read the list that is to be appended at the beginning of the document*/

/*#include <iostream>
#include <string>
using namespace std;

// Node structure for singly linked list
struct Node {
    string data;
    Node* next;
    
    Node(string text) : data(text), next(nullptr) {}
};

// Class for handling document as linked list
class Document {
private:
    Node* head;

public:
    Document() : head(nullptr) {}

    // Function to insert at the beginning of the document
    void insertAtBeginning(string text) {
        Node* newNode = new Node(text);
        newNode->next = head;
        head = newNode;
    }

    // Function to append at the end of the document
    void appendAtEnd(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the document content
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of lines in the document: ";
    cin >> n;
    cin.ignore(); // To ignore the newline after number input

    Document doc;

    // Read n lines and insert them at the beginning of the document
    cout << "Enter the lines for the document:\n";
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        doc.insertAtBeginning(line);
    }

    // Display the initial document
    cout << "Document: \n";
    doc.display();

    // Read the additional line to append at the end
    cout << "Enter the line to append at the end: ";
    string lastLine;
    getline(cin, lastLine);
    doc.appendAtEnd(lastLine);

    // Display the updated document
    cout << "Updated Document: \n";
    doc.display();

    return 0;
}


/* keep Inserting elements at the beginning of a linked list untill user tells not to

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);  // Create a new node
    newNode->next = head;           // Point new node's next to current head
    head = newNode;                 // Update head to point to the new node
    cout << "Node inserted" << endl;
}

// Function to display the entire linked list
void displayList(Node* head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print each node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;  // Initially, the linked list is empty
    int n, choice;

    do {
        // Input integer to insert at the beginning
        cin >> n;
        insertAtBeginning(head, n);  // Insert into the linked list

        // Input choice to continue (0) or stop (1)
        cin >> choice;
    } while (choice != 1);

    // Display the final linked list
    displayList(head);
    cout << "Node ended" << endl;

    return 0;
}


wap to take  number of nodes to be inserted followed by their values in increasing order and then insert another anode according to the order of the element

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node in sorted order
void insertSorted(Node* &head, int val) {
    Node* newNode = new Node(val);

    // If the list is empty or the new node should be inserted at the head
    if (head == nullptr || head->data >= val) {
        newNode->next = head;
        head = newNode;
    } else {
        // Find the position to insert the new node
        Node* current = head;
        while (current->next != nullptr && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    // Input the number of elements in the initial sorted linked list
    cin >> n;

    // Input the initial sorted linked list
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertSorted(head, value);  // Insert in sorted order
    }

    // Input the new element to be inserted
    int newData;
    cin >> newData;

    // Insert the new element in sorted order
    insertSorted(head, newData);

    // Display the updated linked list
    displayList(head);

    return 0;
}

*/