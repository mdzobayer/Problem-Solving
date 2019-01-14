#include <iostream>

using namespace std;

int main ()
{
    cout << "hello World!" << endl;
    cout.put('h');
    cout.put('e');
    cout.put('l');
    cout.put('l');
    cout.put('o');
    cout.put(' ');
    cout.put('w');
    cout.put('o');
    cout.put('r');
    cout.put('l');
    cout.put('d');
    cout.put('!').put('\n');

    cout << "hello World!" << flush;
    cout << "hello World!" << ends;


    return 0;
}
