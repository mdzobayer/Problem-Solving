/*
    If you use this method you can protect
    your program against failure through bad pointers
*/
#include <iostream>

using namespace std;

class BigClass
{
public:
    BigClass()
    {
        pDouble = new double[1000];
    }
    void Tidy_Up()
    {
        delete[] pDouble;
    }
    // No destructor so automatic cleanup won't happen!
    ~BigClass()
    {
        delete[] pDouble;
    }

private:
    double* pDouble;
};

struct BigMem
{
    int* pint;
    double darray[500];
};

void doit(BigClass bc)
{
    BigMem* pLocalBigMem;
    pLocalBigMem = new BigMem;
    pLocalBigMem->pint = new int [1000];
    // (1) pLocalBigMem goes out of scope but memory is still allocated
    // we've just lost (sizeof(double) * 500) + (sizeof(int) * 1000) bytes!
    // (2) BigClass is called by value (which in itself is a problem!) However,
    // in this case we're not even tidying up the memory for the copy - no destructor
    delete[] pLocalBigMem->pint;
    delete pLocalBigMem;
}

int main() {

    /*
    There is no way we can tell wheather a pointer has
    been uninitialized or not. It must be initialized it.
    */

    int* pint{ nullptr }; // now pint is initialized
    /*
    i can't code around my dereference of the pointer to check wheather
    the pointer is initialized
    */
    if (pint != nullptr)
    {
        cout << *pint << endl;  // (3) dereferencing uninitialized pointer
    }

    pint = new int;

    delete pint;
    /*
    We should do every time we delete a pointer is reinitialized
    it to null pointer
    */

    if (pint != nullptr)
    {
        cout << *pint << endl;  // (4) dereferencing deleted pointer - delete does not change pointer value
    }

    BigMem* HugeMem[10];
    for (int x = 0; x < 10; ++x)
    {
        HugeMem[x] = new BigMem;
        HugeMem[x]->pint = new int[100];
    }

    for (int x = 0; x < 10; ++x)
    {
        delete[] HugeMem[x]->pint;
        delete HugeMem[x];
        // (5) HugeMem struct deleted but not memory at pint pointer!
    }

    // (6) Have we deleted pint?? Let's do it again to be sure!
    if (pint != nullptr)
    {
        delete pint;
        pint = nullptr;
    }
    /*
    Deleting a piece of memory twice has result undefined results.
    This is going to cause an error.
    */

    return (0);
}
