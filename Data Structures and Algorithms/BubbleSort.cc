#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//template <typename T1, typename T2>

void display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              std::swap(arr[j], arr[j+1]);
}

int main() {

    const int size = 10;
    int numbers[size];
    srand(unsigned(time(0)));
    for(int i = 0; i < size; ++i) {
        numbers[i] = (rand() % 100) + 1;
    }
    cout << "Unsorted array: " << endl;
    display(numbers, size);
    cout << endl;
    cout << "Sorting array...." << endl;
    bubbleSort(numbers, size);
    cout << endl;
    cout << "Sorted array: " << endl;
    display(numbers, size);

    return (0);
}
