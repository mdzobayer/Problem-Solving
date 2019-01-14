#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int length = 10;

void MakeHeap(int values[])
{
    for (int i = 0; i < length; i++ )
    {
        int index = i;

        while (index != 0)
        {
            int parent = (index - 1) / 2;

            if (values[index] <= values[parent])
                break;

            int temp = values[index];
            values[index] = values[parent];
            values[parent] = temp;

            index = parent;
        }
    }
}

int RemoveTopItem( int values[], int count)
{
    int result = values[0];

    values[0] = values[count];

    int index = 0;

    while(true)
    {
        int child1 = 2 * index + 1;
        int child2 = 2 * index + 2;

        if (child1 >= count)
            child1 = index;

        if (child2 >= count)
            child2 = index;

        if ((values[index] >= values[child1]) && values[index] >= values[child2])
        {
            break;
        }

        int swap_child;

        if (values[child1] > values[child2])
            swap_child = child1;
        else
            swap_child = child2;

        int temp = values[index];
        values[index] = values[swap_child];
        values[swap_child] = temp;

        index = swap_child;
    }

    return result;

}

void HeapSort(int values[])
{
    MakeHeap(values);

    for (int i = length - 1; i > 0; --i)
    {
        int temp = RemoveTopItem(values, i);
        values[i] = temp;
    }
}
int main()
{
    int numbers[10];
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

    HeapSort(numbers);

    cout << "After Sort" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    return (0);
}
