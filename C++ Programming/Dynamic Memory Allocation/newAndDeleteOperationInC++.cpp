#include <iostream>

using namespace std;

int main() {
    int a = 3;
    int *pointer;
    pointer = new(nothrow) int;
    if ( pointer == NULL) {
        cerr << "Error: Memory Allocation Failed" << endl;
    }
    else{
        *pointer = 24;

        cout << pointer << endl;
        cout << *pointer << endl;

        delete pointer;

        pointer = &a;

        cout << *pointer << endl;
    }

    return (0);
}
