#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

int main() {

    int *pointer = NULL;

    cout << "How many items you are gonna enter: ";
    int input;
    cin >> input;

    pointer = new(nothrow) int[input];

    int temp;
    for (int counter = 0; counter < input; ++counter) {
        cout << "Enter the item " << counter + 1  << ": ";
        cin >> temp;
        //*(pointer+counter) = temp;
        pointer[counter] = temp;
    }
    cout << "The items you have entered are " << endl;
    for (int counter = 0; counter < input; ++counter) {
        cout << counter+1 << ". " << *(pointer + counter) << endl;
    }

    cout << *pointer << endl;


    delete []pointer;

    cout << *pointer << endl;

    return (0);
}
