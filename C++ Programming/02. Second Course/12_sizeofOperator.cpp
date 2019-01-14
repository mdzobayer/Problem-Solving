#include <iostream>

using namespace std;

int main(){

    cout << "The size of an integer is " << sizeof(int) << endl;
    cout << "The size of a double is " << sizeof(double) << endl;
    cout << "The size of a string is " << sizeof(string) << endl;
    int num = 1234;
    cout << "The size of num is " << sizeof(num) << endl;
    int *pnum = &num;
    cout << "The size of the pointer pnum is " << sizeof(pnum) << endl;
    cout << "The size of the value pointed at by pnum is " << sizeof(*pnum) << endl;

    int numbers[] = {5,10,15,20,25};
    int size = sizeof(numbers) / sizeof(*numbers);
    cout << sizeof(numbers) << " " << size << endl;
    cout << sizeof(*numbers) << endl;
    cout << "The number of elements in number is "
         << size << endl;
    return (0);
}
