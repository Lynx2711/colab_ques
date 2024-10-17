/* search for elements in fixed size stack implemented with array: pushing and searching

#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    int stackArray[30]; // Maximum size of the stack is 30

public:
    // Constructor to initialize the stack
    Stack() {
        maxSize = 30;
        top = -1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow. Cannot push " << value << "." << endl;
        } else {
            stackArray[++top] = value;
        }
    }

    // Function to search for an element in the stack
    bool search(int element) {
        for (int i = top; i >= 0; i--) {
            if (stackArray[i] == element) {
                return true; // Element found
            }
        }
        return false; // Element not found
    }
};

int main() {
    int n;
    cin >> n;  

    Stack s;

    if (n == 0) {
        cout << "The STACK is empty" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        s.push(element);
    }
    int searchElement;
    cin >> searchElement;
    if (s.search(searchElement)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
*/
/*
stack using linked list to convert binary to decimal

#include <iostream>
using namespace std;

// Node structure for the linked list implementation of the stack
struct Node {
    int data;  // To store the binary digit
    Node* next;  // Pointer to the next node
};

// Stack class using linked list
class Stack {
private:
    Node* top;
    int maxSize;
    int currentSize;

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
        maxSize = 32;
        currentSize = 0;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (currentSize >= maxSize) {
            cout << "Stack overflow. Cannot push more than " << maxSize << " elements." << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        currentSize++;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from an empty stack." << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        currentSize--;
        return poppedValue;
    }

    // Destructor to free the memory used by the stack
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Function to convert a decimal number to binary using a stack
void decimalToBinary(int decimal) {
    Stack stack;

    // Edge case for decimal number 0
    if (decimal == 0) {
        cout << "Binary representation: 0" << endl;
        return;
    }

    // Push binary digits onto the stack
    while (decimal > 0) {
        int remainder = decimal % 2;
        stack.push(remainder);
        decimal /= 2;
    }

    // Output the binary representation
    cout << "Binary representation: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();  // Pop and print each binary digit
    }
    cout << endl;
}

int main() {
    int d;
    cin >> d;  // Input decimal number

    // Convert the decimal number to binary
    decimalToBinary(d);

    return 0;
}

*/