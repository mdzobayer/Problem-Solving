#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Copy
{
public:
    Copy()
    {
        largeMemBlock = new int[1000000];
        memBlockSize = 1000000;
    }
    ~Copy()
    {
        if (largeMemBlock != nullptr)
        {
            delete [] largeMemBlock;
        }
    }
    Copy(const Copy& clone) // Copy Constructor
    {
        cout << "Copy Constructor called - Copying largeMemBlock" << endl;
        largeMemBlock = new int[clone.memBlockSize];
        memcpy(largeMemBlock, clone.largeMemBlock, clone.memBlockSize * 4);
        memBlockSize = clone.memBlockSize;
    }
private:
    int* largeMemBlock;
    int memBlockSize;
};
void Doit1(Copy c) // copy (by value) parameter
{

}
Copy Doit2()
{
    Copy x;
    return x; // copy return
}
int main()
{
    Copy one;           // Default Constructor
    Copy two(one);      // Copy Constructor
    Copy three = one;   // Copy constructor by assignment

    Doit1(one);         // Copy parameter
    Doit2();            // Copy return

    vector<Copy> v;
    // Universal Initialization
    v.push_back({});

    queue<Copy> q;
    q.push({});

    list<Copy> l;
    l.push_back({});

    return 0;
}
