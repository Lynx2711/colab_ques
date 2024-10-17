/*
occurences of an element in a queue(fixed array size)
#include <iostream>
using namespace std;

#define MAX_SIZE 100  // Maximum size of the queue

class Queue {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];  // Array to store the queue elements
    int size;  // Number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more elements." << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;  // Circular increment
        arr[rear] = value;
        size++;
    }

    // Function to count the occurrences of a specific book ID
    int countOccurrences(int bookID) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[(front + i) % MAX_SIZE] == bookID) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n, bookID;
    cin >> n;  // Input the number of book IDs

    Queue queue;

    // Enqueue the book IDs
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        queue.enqueue(id);
    }

    // Input the book ID to search for occurrences
    cin >> bookID;

    // Count and print the occurrences of the given book ID
    int count = queue.countOccurrences(bookID);
    cout << "Occurrences of " << bookID << " in the queue: " << count << endl;

    return 0;
}
*/

/*
enqueue, get front and get rear
#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queueArray;  // Dynamic array to hold the queue elements

public:
    // Constructor to initialize the queue with a specific capacity
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        queueArray = new int[capacity];
    }

    // Destructor to clean up allocated memory
    ~Queue() {
        delete[] queueArray;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front > rear);
    }

    // Function to add an order to the queue
    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more orders." << endl;
            return;
        }
        queueArray[++rear] = order;  // Add the new order to the end of the queue
    }

    // Function to get the front order in the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 to indicate empty queue
        }
        return queueArray[front];
    }

    // Function to get the rear order in the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 to indicate empty queue
        }
        return queueArray[rear];
    }
};

int main() {
    int N;
    cin >> N;  // Input capacity of the queue

    Queue orderQueue(N);  // Create a queue with specified capacity

    // Input customer orders
    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;
        orderQueue.enqueue(order);  // Enqueue each order
    }

    // Display front and rear elements of the queue
    cout << "Front element: " << orderQueue.getFront() << endl;
    cout << "Rear element: " << orderQueue.getRear() << endl;

    return 0;
}
*/

/*
linked list based queue enqueue,get front , get rear
#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string task;   // Task description
    Node* next;    // Pointer to the next node

    Node(string t) : task(t), next(nullptr) {} // Constructor
};

// Queue class using linked list
class Queue {
private:
    Node* front;   // Pointer to the front of the queue
    Node* rear;    // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue a task
    void enqueue(string task) {
        Node* newNode = new Node(task); // Create a new node
        if (isEmpty()) {
            front = rear = newNode; // If the queue is empty, set front and rear to new node
        } else {
            rear->next = newNode; // Add new node at the end of the queue
            rear = newNode;       // Update rear to new node
        }
    }

    // Function to get the front task
    string getFront() {
        if (isEmpty()) {
            return "Queue is empty"; // Handle empty queue
        }
        return front->task; // Return front task description
    }

    // Function to get the rear task
    string getRear() {
        if (isEmpty()) {
            return "Queue is empty"; // Handle empty queue
        }
        return rear->task; // Return rear task description
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr; // Return true if front is null
    }
};

int main() {
    int n;
    cin >> n;           // Input number of tasks
    cin.ignore();      // Ignore newline character after reading n

    Queue todoQueue;   // Create a queue for tasks

    // Input task descriptions
    for (int i = 0; i < n; i++) {
        string task;
        getline(cin, task); // Read the task description
        todoQueue.enqueue(task); // Enqueue the task
    }

    // Display front and rear tasks
    cout << "Front Task: " << todoQueue.getFront() << endl;
    cout << "Rear Task: " << todoQueue.getRear() << endl;

    return 0;
}
*/

/*
reverse a queue
#include <iostream>
#include <stack>
using namespace std;

// Node structure for the linked list
struct Node {
    int position;    // Customer position
    Node* next;      // Pointer to the next node

    Node(int pos) : position(pos), next(nullptr) {} // Constructor
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue a customer position
    void enqueue(int position) {
        Node* newNode = new Node(position); // Create a new node
        if (rear) {
            rear->next = newNode; // Add new node at the end of the queue
        } else {
            front = newNode; // If the queue is empty, set front to new node
        }
        rear = newNode; // Update rear to new node
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr; // Return true if front is null
    }

    // Function to display the queue in reverse order
    void displayReversed() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl; // Handle empty queue
            return;
        }

        stack<int> positions; // Stack to reverse the order

        // Traverse the linked list and push positions onto the stack
        Node* current = front;
        while (current) {
            positions.push(current->position); // Push customer position onto the stack
            current = current->next; // Move to the next node
        }

        // Display the positions in reverse order
        cout << "Queue: ";
        while (!positions.empty()) {
            cout << positions.top() << " "; // Print the top element of the stack
            positions.pop(); // Remove the top element from the stack
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n; // Input number of customers

    Queue customerQueue; // Create a queue for customers

    // Input customer positions
    for (int i = 0; i < n; i++) {
        int position;
        cin >> position; // Read customer position
        customerQueue.enqueue(position); // Enqueue the customer position
    }

    // Display the queue in reversed order
    customerQueue.displayReversed();

    return 0;
}
*/

/*calculate average of elements in a queue

#include <iostream>
#include <iomanip> // For setting precision
using namespace std;

#define MAX_SIZE 100 // Maximum size of the queue

class Queue {
private:
    int elements[MAX_SIZE]; // Array to store queue elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int count; // Number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue() : front(0), rear(-1), count(0) {}

    // Function to enqueue an element
    void enqueue(int value) {
        if (count < MAX_SIZE) {
            rear = (rear + 1) % MAX_SIZE; // Circular increment
            elements[rear] = value; // Add the new element
            count++; // Increment count
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0; // Return true if count is zero
    }

    // Function to calculate the average of elements in the queue
    double calculateAverage() {
        if (isEmpty()) {
            return 0.0; // Return 0 if the queue is empty
        }

        double sum = 0; // To hold the sum of elements
        for (int i = 0; i < count; i++) {
            sum += elements[(front + i) % MAX_SIZE]; // Access elements in circular manner
        }
        return sum / count; // Return the average
    }
};

int main() {
    int n;
    cin >> n; // Input number of elements

    Queue q; // Create a queue

    // Input elements to enqueue
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Read the element
        q.enqueue(value); // Enqueue the element
    }

    // Output the average or the empty message
    if (q.isEmpty()) {
        cout << "Queue is empty." << endl; // Handle empty queue
    } else {
        double average = q.calculateAverage(); // Calculate average
        cout << fixed << setprecision(2) << average << endl; // Output average rounded to 2 decimal places
    }

    return 0;
}
*/

/*reverse the characters in a string using queue data structure
#include <iostream>
#include <queue>  // For the queue data structure
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input; // Variable to hold the input string
    getline(cin, input); // Read the entire line of input

    queue<char> charQueue; // Queue to store characters

    // Enqueue each character of the input string
    for (char c : input) {
        charQueue.push(c);
    }

    string reversedString; // Variable to hold the reversed string

    // Dequeue characters to build the reversed string
    while (!charQueue.empty()) {
        reversedString += charQueue.front(); // Append the front character to reversedString
        charQueue.pop(); // Remove the front character from the queue
    }

    // Reverse the constructed string
    reverse(reversedString.begin(), reversedString.end());

    // Output the reversed string
    cout << reversedString << endl;

    return 0;
}
*/

/*
priority queue
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Book structure to hold book details
struct Book {
    string title;
    int quantity;
    int priority;

    // Overload operator for priority queue
    bool operator<(const Book &other) const {
        return priority > other.priority; // Higher priority value means lower priority
    }
};

class BookstoreInventory {
private:
    priority_queue<Book> inventory; // Priority queue to manage books

public:
    void addBook(const string &title, int quantity, int priority) {
        Book newBook = {title, quantity, priority};
        inventory.push(newBook);
        cout << "Book added to the inventory" << endl;
    }

    void restockBook() {
        if (inventory.empty()) {
            cout << "No books in the inventory" << endl;
            return;
        }
        Book nextBook = inventory.top(); // Get the book with the highest priority
        inventory.pop(); // Remove the book from the queue
        cout << "Restocked book: " << nextBook.title << endl;
    }

    void viewNextBook() {
        if (inventory.empty()) {
            cout << "No books in the inventory." << endl;
            return;
        }
        cout << "Next book to restock: " << inventory.top().title << endl;
    }
};

int main() {
    BookstoreInventory bookstore;
    int choice;

    // Input loop for processing choices
    while (true) {
        cin >> choice;
        cin.ignore(); // Ignore the newline character after the choice

        switch (choice) {
            case 1: { // Add book
                string title;
                int quantity, priority;

                getline(cin, title); // Read book title
                cin >> quantity; // Read current quantity
                cin >> priority; // Read restock priority

                if (priority >= 1 && priority <= 5) {
                    bookstore.addBook(title, quantity, priority);
                }
                break;
            }
            case 2: // Restock book
                bookstore.restockBook();
                break;
            case 3: // View the next book to restock
                bookstore.viewNextBook();
                break;
            case 4: // Exit
                cout << "Exiting the application" << endl;
                return 0;
            default:
                cout<<"Invalid choice. Please enter a valid option"<<endl;
                break;
        }
    }

    return 0;
}
*/

/*
priority queue using array-based approach
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}

    // Function to insert an element into the priority queue
    void insert(int element, int priority) {
        if (size < MAX_SIZE) {
            elements[size] = element;
            priorities[size] = priority;
            size++;
            sortQueue();  // Sort after every insertion
        }
    }

    // Function to sort the queue based on priorities
    void sortQueue() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                // Compare priorities, swap if necessary
                if (priorities[j] > priorities[j + 1]) {
                    swap(priorities[j], priorities[j + 1]);
                    swap(elements[j], elements[j + 1]);
                }
            }
        }
    }

    // Function to remove the element with the highest priority
    void remove() {
        if (size == 0) {
            return; // No element to remove
        }

        // Shift elements to remove the one with the highest priority
        for (int i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size--;
    }

    // Function to print the elements in the priority queue based on their priorities
    void print() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << (i < size - 1 ? " " : "");
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int N;

    cin >> N; // Read the number of elements to be inserted
    for (int i = 0; i < N; i++) {
        int element, priority;
        cin >> element >> priority; // Read element and its priority
        pq.insert(element, priority);
    }

    pq.print(); // Print the initial state of the priority queue

    pq.remove(); // Perform the dequeue operation

    pq.print(); // Print the state of the priority queue after removing the highest priority element

    return 0;
}
*/