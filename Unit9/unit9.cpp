#include <iostream>
using namespace std;

// Node class representing each month's sales
class Node {
public:
    int sales;
    Node* next;

    Node(int sales) {
        this->sales = sales;
        this->next = nullptr;
    }
};

// Function to insert sales data at the end of the list
void insertion(Node* &head, int val) {
    Node* newNode = new Node(val);
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

// Function to compute the sum of the last m months
int SumOfLastMonths(Node* &head, int n, int m) {
    Node* temp = head;

    // Skip the first (n - m) nodes to start summing from the correct month
    int skip = n - m;
    while (skip > 0 && temp != nullptr) {
        temp = temp->next;
        skip--;
    }

    // Sum the sales of the last m months
    int sum = 0;
    while (temp != nullptr) {
        sum += temp->sales;
        temp = temp->next;
    }

    return sum;
}

// Main function
int main() {
    int n, m, sales;
    Node* head = nullptr;  // Initialize the head of the linked list

    // Input number of months
    cout << "Enter the number of months: ";
    cin >> n;

    // Input sales data for each month
    cout << "Enter sales data for each month: ";
    for (int i = 0; i < n; i++) {
        cin >> sales;
        insertion(head, sales);  // Insert sales data into the linked list
    }

    // Input the number of recent months to sum
    cout << "Enter the number of last months to sum: ";
    cin >> m;

    // Get the sum of sales for the last m months
    int result = SumOfLastMonths(head, n, m);

    // Output the result
    cout << "The sum of sales for the last " << m << " months is: " << result << endl;

    return 0;
}


/*check if the word if palindrome or not

#include <iostream>
#include <vector>
using namespace std;

// Node class to store each character
class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert characters into the linked list
void insert(Node* &head, char val) {
    Node* newNode = new Node(val);
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

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    vector<char> charList;
    Node* temp = head;
    
    // Traverse the linked list and store the characters in a vector
    while (temp != nullptr) {
        charList.push_back(temp->data);
        temp = temp->next;
    }
    
    // Check if the characters form a palindrome
    int start = 0;
    int end = charList.size() - 1;
    while (start < end) {
        if (charList[start] != charList[end]) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}

int main() {
    Node* head = nullptr;
    char ch;
    
    cout << "Enter characters (space-separated) and $ to stop: ";
    while (cin >> ch && ch != '$') {
        insert(head, ch);  // Insert each character into the linked list
    }
    
    // Check if the linked list represents a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome" << endl;
    } else {
        cout << "The linked list is not a palindrome" << endl;
    }
    
    return 0;
}

*/