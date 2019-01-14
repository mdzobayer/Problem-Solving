#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void MergeSort(int values[], int scratch[], int start, int end)
{
    if (start == end)
    {
        return;
    }

    int midpoint = (start + end) / 2;

    MergeSort (values, scratch, start, midpoint);
    MergeSort (values, scratch, midpoint + 1, end);

    int left_index = start;
    int right_index = midpoint + 1;
    int scratch_index = left_index;

    while ((left_index <= midpoint) && (right_index <= end))
    {
        if (values[left_index] <= values[right_index])
        {
            scratch[scratch_index] = values[left_index];
            left_index = left_index + 1;
        }
        else
        {
            scratch[scratch_index] = values[right_index];
            right_index = right_index + 1;
        }
        scratch_index = scratch_index + 1;
    }

    for (int i = left_index; i <= midpoint; i++)
    {
        scratch[scratch_index] = values[i];
        scratch_index = scratch_index + 1;
    }

    for (int i = right_index; i <= end; i++)
    {
        scratch[scratch_index] = values[i];
        scratch_index = scratch_index + 1;
    }

    for (int i = start; i <= end; i++)
    {
        values[i] = scratch[i];
    }

}

int main()
{
    const int size = 10;
    int numbers[size];
    int scratch[100];

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

    MergeSort(numbers, scratch, 0, 9);

    cout << "After Sort" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    return (0);
}
