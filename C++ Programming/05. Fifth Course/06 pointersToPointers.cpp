#include <iostream>

using namespace std;

int main() {

    int x = 99;             // integer x
    int* pint = &x;         // pointer to an integer
    int** ppint = &pint;    // pinter to a pointer to an integer
    int*** pppint;
    pppint = &ppint;

    cout << x << endl;
    cout << *pint << endl;
    cout << **ppint << endl;
    cout << ***pppint << endl;

    cout << "Address of x = " << hex << &x << endl;
    cout << "Contents of pint = " << hex << pint << endl;
    cout << "Address of pint = " << hex << &pint << endl;
    cout << "Contents of ppint = " << hex << ppint << endl;

    int* pnumbers[10];         // array of pointers to integer

    for (int x = 0; x < 10; ++x) {

        pnumbers[x] = new(nothrow) int;   // allocate memory to each pointer
        *pnumbers[x] = x;       // initialize memory at pointer
    }

    int** ppnumbers;
    cout << endl;
    for( ppnumbers = pnumbers; ppnumbers <= &pnumbers[9]; ++ppnumbers)
    {
        cout << **ppnumbers << '\t';
    }


    for (int x = 0; x < 10; ++x) {
        delete pnumbers[x];
    }

    return (0);
}
/*
a pointer can point any item in memory. A pointer is itself a variable in memory
In therefore stands for reason. We should be auto point one pointer at another
pointer.*/
