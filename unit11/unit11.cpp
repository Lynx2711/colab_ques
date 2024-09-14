#include <iostream>
using namespace std;

// Node class for tasks
class Node {
public:
    int task;       // Task ID (integer)
    Node* next;     // Pointer to the next task

    // Constructor to initialize a task node
    Node(int value = 0) {
        task = value;
        next = NULL;
    }
};

// Function to add a task at the beginning of the list
void addTask(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node for the task
    newNode->next = head->next;      // Insert the new node after the ground node
    head->next = newNode;            // Update the ground node to point to the new task
}

// Function to display the tasks in the list
void displayTasks(Node* head) {
    Node* temp = head->next; // Skip the ground node
    while (temp != NULL) {
        cout << temp->task << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* groundHead = new Node(); // Create a grounded header list
    int task;

    // Input task IDs until -1 is entered
    while (true) {
        cin >> task;
        if (task == -1) break; // End of input
        addTask(groundHead, task); // Add each task to the beginning of the list
    }

    // Output the tasks in the order they were added
    displayTasks(groundHead);

    return 0;
}


/*
Remove all occurences of a user defined number from the list using ground headed list

#include <iostream>
using namespace std;

// Node class for stock quantities
class Node {
public:
    int quantity;   // Stock quantity
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with quantity and NULL next
    Node(int value = 0) {
        quantity = value;
        next = NULL;
    }
};

// Function to add a stock quantity to the end of the list
void addStock(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node
    Node* temp = head;

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Add new node at the end
}

// Function to remove all occurrences of a given quantity
void removeQuantity(Node*& head, int value) {
    Node* temp = head->next;  // Start after the ground node
    Node* prev = head;        // Previous node starts at the ground

    while (temp != NULL) {
        if (temp->quantity == value) {
            prev->next = temp->next; // Remove the node from the list
            delete temp;             // Free the memory
            temp = prev->next;       // Move to the next node
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Function to display the stock quantities
void displayStocks(Node* head) {
    Node* temp = head->next; // Skip the ground node
    while (temp != NULL) {
        cout << temp->quantity << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* groundHead = new Node(); // Ground-headed linked list
    int n, quantityToRemove, value;

    // Input number of stock quantities
    cin >> n;

    // Input the stock quantities and add to the list
    for (int i = 0; i < n; i++) {
        cin >> value;
        addStock(groundHead, value);
    }

    // Input the quantity to be removed
    cin >> quantityToRemove;

    // Remove all occurrences of the given quantity
    removeQuantity(groundHead, quantityToRemove);

    // Display the updated list of stock quantities
    displayStocks(groundHead);

    return 0;
}


*/

/*

count the number of elements in a ll using ground header(-1 represents end of the list)
#include <iostream>
using namespace std;

// Node class for inventory items
class Node {
public:
    int quantity;   // Item quantity
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with quantity and NULL next
    Node(int value = 0) {
        quantity = value;
        next = NULL;
    }
};

// Function to add an item to the inventory (at the end of the list)
void addItem(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node
    Node* temp = head;

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Add new node at the end
}

// Function to count the number of items in the inventory
int countItems(Node* head) {
    int count = 0;
    Node* temp = head->next; // Skip the ground node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* groundHead = new Node(); // Ground-headed linked list
    int quantity;

    // Input item quantities until -1 is entered
    while (true) {
        cin >> quantity;
        if (quantity == -1) break; // End of input
        addItem(groundHead, quantity); // Add each item to the inventory list
    }

    // Output the total number of items in the inventory
    cout << countItems(groundHead) << endl;

    return 0;
}

*/