#include <iostream>

using namespace std;

int main(){
    const int size = 4;
    int numbers[size] = {5,10,15,20};
    for(int i = 0; i < size; ++i)
        cout << numbers[i] << " ";
    //Using pointer variable
    int *pnumbers;
    pnumbers = &numbers[0];
    cout << endl << *pnumbers << " " << *(pnumbers + 1) << endl;
    for(int i = 0; i < size; ++i)
        cout << *(pnumbers+i) << " ";
    //Using array elements (array is a short form of pointer)
    cout << endl << *numbers << endl;
    for(int i = 0; i < size; ++i)
        cout << *(numbers+i) << " ";
    return (0);
}
