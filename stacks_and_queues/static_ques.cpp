/*char based stack : type a character(push) , undo typing(pop) , view current text(display),exit all this is choice based

#include <iostream>
using namespace std;

class TextEditor {
    char stack[100];  
    int top;

public:
    TextEditor() {
        top = -1; // Stack is initially empty
    }
    void push(char ch) {
        if (top < 99) {
            stack[++top] = ch;
            cout << "Typed character: " << ch << endl;
        } else {
            cout << "Text editor buffer is full." << endl;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Text editor buffer is empty. Nothing to undo." << endl;
        } else {
            cout << "Undo: Removed character " << stack[top--] << endl;
        }
    }
    void display() {
        if (top == -1) {
            cout << "Text editor buffer is empty." << endl;
        } else {
            cout << "Current text: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    while (true) {
        cin >> choice;
        switch (choice) {
            case 1: 
                cin >> ch;
                editor.push(ch);
                break;

            case 2: 
                editor.pop();
                break;

            case 3: 
                editor.display();
                break;

            case 4: 
                return 0;

            default: 
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}

*/

/*
stack using linked list: push,pop,display and handle stack underflow all these are choice based

#include <iostream>
using namespace std;

struct Node {
    int data;  
    Node* next; 
};

class Stack {
    Node* top; 

public:
    Stack() {
        top = nullptr;  
    }
    void push(int value) {
        Node* newNode = new Node();  
        newNode->data = value;       
        newNode->next = top;         
        top = newNode;               
        cout << value << " is pushed onto the stack" << endl;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;  
        } else {
            Node* temp = top;   
            cout << top->data << " is popped from the stack" << endl;
            top = top->next;    
            delete temp;        
        }
    }
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl; 
        } else {
            cout << "Elements in the stack: ";
            Node* current = top;  
            while (current != nullptr) {
                cout << current->data << " ";  
                current = current->next;      
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack; 
    int choice, value;

    while (true) {
        cin >> choice;  
        switch (choice) {
            case 1:  
                cin >> value;
                stack.push(value);
                break;

            case 2:  
                stack.pop();
                break;

            case 3:  
                stack.display();
                break;

            case 4:  
                cout << "Exiting the program" << endl;
                return 0;

            default:  
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
*/

/* array basesd queue: add at the end of the queue,pop form the queue and display
#include <iostream>
using namespace std;

#define MAX 5  // Maximum number of helpdesk tickets in the queue

class HelpdeskQueue {
    int queue[MAX];  // Array to hold the ticket IDs
    int front, rear; // Pointers to the front and rear of the queue

public:
    HelpdeskQueue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return (rear == MAX - 1);
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    void enqueue(int ticketID) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            if (front == -1) front = 0;  // Set front to 0 if the first element is added
            queue[++rear] = ticketID;   // Increment rear and add ticketID to the queue
            cout << "Helpdesk Ticket ID " << ticketID << " is enqueued." << endl;
        }
    }

    // Function to dequeue a ticket from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Dequeued Helpdesk Ticket ID: " << queue[front++] << endl;
            if (front > rear) {  // Reset front and rear when queue becomes empty
                front = -1;
                rear = -1;
            }
        }
    }

    // Function to display all ticket IDs in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Helpdesk Ticket IDs in the queue are: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HelpdeskQueue helpdeskQueue;
    int choice, ticketID;

    while (true) {
        cin >> choice;  
        switch (choice) {
            case 1:  
                cin >> ticketID;
                helpdeskQueue.enqueue(ticketID);
                break;

            case 2:  
                helpdeskQueue.dequeue();
                break;

            case 3:  
                helpdeskQueue.display();
                break;

            case 4:  
                cout << "Exiting the program" << endl;
                return 0;

            default:  
                cout << "Invalid option." << endl;
                break;
        }
    }
    return 0;
}
*/

/*
queue with linked list : enqueue,dequeue and display
#include <iostream>
using namespace std;

// Node class to represent each customer in the queue
class Node {
public:
    int data;       // Customer ID
    Node* next;     // Pointer to the next node
};

// Queue class to manage the linked list
class Queue {
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (add) a customer ID to the rear of the queue
    void enqueue(int customerID) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = customerID;
        newNode->next = nullptr;

        if (isEmpty()) {
            // If the queue is empty, both front and rear point to the new node
            front = rear = newNode;
        } else {
            // Otherwise, add the new node to the end of the queue
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Customer ID " << customerID << " is enqueued" << endl;
    }

    // Function to dequeue (remove) a customer ID from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;    // Temporary pointer to the front node
            cout << "Dequeued customer ID: " << front->data << endl;
            front = front->next;   // Move the front pointer to the next node

            // If the queue is now empty, set rear to nullptr as well
            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;  // Free the memory of the dequeued node
        }
    }

    // Function to display all customer IDs in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Customer IDs in the queue are: ";
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue customerQueue;
    int choice, customerID;

    while (true) {
        cin >> choice;  // Read the user's choice

        switch (choice) {
            case 1:  // Enqueue operation
                cin >> customerID;
                customerQueue.enqueue(customerID);
                break;

            case 2:  // Dequeue operation
                customerQueue.dequeue();
                break;

            case 3:  // Display the queue
                customerQueue.display();
                break;

            case 4:  // Exit the program
                return 0;

            default:  // Invalid option
                cout << "Invalid option" << endl;
                break;
        }
    }

    return 0;
}
*/

/*
priority queuebased on severity of injury and dequeued based on priority

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Patient {
    string name;   
    int severity; 
    // Overloading the '<' operator to make the priority queue a max-heap based on severity
    bool operator<(const Patient& other) const {
        return severity < other.severity;
    }
};

int main() {
    int N;  
    cin >> N;

    // Priority queue to store patients, sorted by severity (max-heap)
    priority_queue<Patient> pq;
    for (int i = 0; i < N; i++) {
        string name;
        int severity;
        cin >> name >> severity;
        pq.push(Patient{name, severity});  // Add the patient to the queue
    }
    while (!pq.empty()) {
        Patient p = pq.top();  // Get the patient with the highest severity
        pq.pop();  // Remove the patient from the queue
        cout << "Treating patient: " << p.name << " (Severity: " << p.severity << ")" << endl;
    }

    return 0;
}
*/