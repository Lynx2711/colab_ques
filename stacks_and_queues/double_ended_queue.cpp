/*
#include <iostream>
#include <deque>  // Include deque header for double-ended queue

using namespace std;

int main() {
    int n;
    cin >> n;  // Input the number of patients

    deque<int> waitingList;

    // Input the patient IDs and add them to the deque
    for (int i = 0; i < n; i++) {
        int patientID;
        cin >> patientID;
        waitingList.push_back(patientID);  // Add patients to the back of the deque
    }

    // Treat the first patient (remove the first element)
    if (!waitingList.empty()) {
        waitingList.pop_front();  // Remove the first patient
    }

    // Output the remaining patients in the deque
    for (int patientID : waitingList) {
        cout << patientID << " ";
    }
    cout << endl;

    return 0;
}
*/

/*display without any duplicates
#include <iostream>
#include <deque>
#include <unordered_set>  // To keep track of unique elements

using namespace std;

int main() {
    deque<int> userIDs;
    unordered_set<int> seen;  // Set to track duplicate user IDs
    int id;

    // Read input until -1 is encountered
    while (cin >> id && id != -1) {
        // Only add the ID if it's not already in the set
        if (seen.find(id) == seen.end()) {
            userIDs.push_back(id);  // Add unique ID to deque
            seen.insert(id);  // Mark the ID as seen
        }
    }

    // Output the unique IDs in the order they were entered
    for (int uid : userIDs) {
        cout << uid << " ";
    }
    cout << endl;

    return 0;
}
*/

/*
keep adding until -1
#include <iostream>
#include <deque>
#include <algorithm>  // For std::max_element

using namespace std;

int main() {
    deque<int> numbers;
    int num;

    // Read input until -1 is encountered
    while (cin >> num && num != -1) {
        numbers.push_back(num);
    }

    // If deque is not empty, find and print the maximum element
    if (!numbers.empty()) {
        int maxElement = *max_element(numbers.begin(), numbers.end());
        cout << maxElement << endl;
    } else {
        cout << "Deque is empty." << endl;
    }

    return 0;
}
*/

/*dequeue using array and insert at front and delete at front
#include <iostream>
using namespace std;

class Deque {
    int arr[100]; // Maximum size of the deque is 100
    int front, rear, size;

public:
    // Constructor to initialize deque
    Deque() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Function to insert element at the front of deque
    void insertFront(int value) {
        if (front == -1) {
            front = rear = 0;
        } else {
            front++;
        }
        arr[front] = value;
        size++;
    }

    // Function to delete element from the front of deque
    void deleteFront() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
        } else {
            front--;
            size--;
        }
    }

    // Function to return the current front element
    int getFront() {
        if (size == 0) {
            return -1; // Indicate deque is empty
        }
        return arr[front];
    }
};

int main() {
    int n; // Size of the deque
    cin >> n;

    Deque deque;
    int value;

    // Insert elements into the deque from the front
    for (int i = 0; i < n; i++) {
        cin >> value;
        deque.insertFront(value);
    }

    int deleteCount;
    cin >> deleteCount;

    // Output the current front element
    cout << "The front element is " << deque.getFront() << endl;

    // Delete elements from the front
    for (int i = 0; i < deleteCount; i++) {
        deque.deleteFront();
    }

    // Output the new front element after deletion
    if (deque.getFront() == -1) {
        cout << "After deletion, the front element becomes -1" << endl;
    } else {
        cout << "After deletion, the front element becomes " << deque.getFront() << endl;
    }

    return 0;
}
*/