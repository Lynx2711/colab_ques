#include <iostream>
#include <algorithm> // for sort
using namespace std;

void calculateFrequency(int* arr, int n) {
    // Sort the array to get product IDs in ascending order
    sort(arr, arr + n);

    // Initialize pointers
    int* current = arr;
    int* end = arr + n;

    // Traverse through the sorted array
    while (current < end) {
        int count = 1; // Count occurrences of the current product
        int* next = current + 1;

        // Count how many times the current product ID appears
        while (next < end && *next == *current) {
            count++;
            next++;
        }

        // Output the product ID and its count
        if (count == 1) {
            cout << *current << " - " << count << " time" << endl;
        } else {
            cout << *current << " - " << count << " times" << endl;
        }

        // Move to the next unique product ID
        current = next;
    }
}

int main() {
    int n;
    
    // Input the number of products sold
    cin >> n;

    // Dynamically allocate memory for the array of product IDs
    int* arr = new int[n];

    // Input the product IDs
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i); // Using pointer arithmetic
    }

    // Calculate the frequency of each product
    calculateFrequency(arr, n);

    // Free the allocated memory
    delete[] arr;

    return 0;
}



/*#include <iostream>
#include <cstring> // for strlen
using namespace std;

// Function to count consonants in the entire paragraph
int countConsonants(char* paragraph) {
    int consonantCount = 0;
    for (int i = 0; i < strlen(paragraph); i++) {
        char ch = tolower(*(paragraph + i)); // Convert character to lowercase
        // Check if the character is a consonant
        if ((ch >= 'a' && ch <= 'z') && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            consonantCount++;
        }
    }
    return consonantCount;
}

int main() {
    char paragraph[1000]; // Assuming maximum length of paragraph is 1000 characters

    // Input the entire paragraph (can include spaces)
    cout << "Enter the paragraph: ";
    cin.getline(paragraph, 1000); // Reads an entire line including spaces

    // Count the consonants in the paragraph
    int totalConsonants = countConsonants(paragraph);

    // Output the total number of consonants
    cout << "Total number of consonants: " << totalConsonants << endl;

    return 0;
}
*/