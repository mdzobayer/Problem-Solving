#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quickSort(int values[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int divider = values[start];

    int lo = start;
    int hi = end;

    while(true)
    {
        while(values[hi] >= divider)
        {
            hi = hi - 1;
            if (hi <= lo)
            {
                break;
            }
        }
        if (hi <= lo)
        {
            values[lo] = divider;
            break;
        }

        values[lo] = values[hi];

        lo += 1;

        while(values[lo] < divider)
        {
            lo += 1;
            if (lo >= hi)
            {
                break;
            }
        }
        if (lo >= hi)
        {
            lo = hi;
            values[hi] = divider;
            break;
        }
        values[hi] = values[lo];
    }
    quickSort(values, start, lo - 1);
    quickSort(values, lo + 1, end);
}

int main()
{

    int numbers[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = (rand() % 100) + 1;
    }
    cout << "Before Sort" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    quickSort(numbers, 0, 10);

    cout << "After Sort" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    return (0);
}
