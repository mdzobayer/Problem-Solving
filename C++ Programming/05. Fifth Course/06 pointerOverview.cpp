#include <iostream>
using namespace std;
#include <memory.h>

struct Date
{
    int dd;
    int mm;
    int ccyy;
};
int main() {

    int* pint;  // The type of pint is: pint is a pointer to an int.

    // Pointer are initialization in one of several ways:

    pint = 0;       // old method of initialization
    pint = nullptr; // newer method of initialization
    int* pint2{ nullptr };  // creation & universal initialization
    int x = 999;
    pint = &x;      // initialization with the address of x
    pint = new int; // initialization with the address of a dynamically allocated integer

    pint = new int; // pointer to int initialization with dynamically allocated integer
    Date* pDate = new Date; // pointer to date initialized with dynamic date

    *pint = 99; // dereference pint & set the value at pint to 99
    cout << *pint << endl; // dereference pint & retrieve its value

    pDate->dd = 21; // dereference pDate & set its dd member to 21
    cout << pDate->dd << endl; // dereference pDate & retrieve its dd member

    //      'C'                                     'C++'
    pint = (int*)malloc(sizeof(int));       // pint = new int;
    free(pint);                             // delete pint;

    pint = (int*)malloc(sizeof(int) * 10);  // pint = new int[10];
    free(pint);                             // delete [] pint;

    return (0);
}
