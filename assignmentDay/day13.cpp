#include<iostream>
using namespace std;

int main() {
    int *ptr = new int; 
    *ptr = 10;
    cout << "Value stored at ptr: " << *ptr << endl;
    return 0;
}
