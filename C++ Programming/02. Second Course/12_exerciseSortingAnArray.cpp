#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void buildArray(int arr[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
        arr[i] = rand() % 100 + 1;
}
void displayArray(int arr[], int size){
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void exchangeSort(int arr[], int size){
    for(int i = 0; i < size-1; ++i)
        for(int j = i + 1; j < size; ++j){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
                displayArray(arr, size);
                cout << endl;
            }
        }
}
int main(){

    cout << "Hello world!" << endl;
    const int size = 3;
    int numbers[size];
    buildArray(numbers, size);
    displayArray(numbers,size);
    cout << endl;
    exchangeSort(numbers, size);
    displayArray(numbers,size);

    return (0);
}
