#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void buildArray(int arr[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
        arr[i] = rand() % 100 + 0;

}
void initArray(int arr[], int size);
void displayArray(int arr[], int size){
   for(int i = 0; i < size; ++i)
        cout << i << ": " << arr[i] << endl;
}
int main(){
    const int size = 101;
    int numbers[size];
    //initArray(numbers,size);
    buildArray(numbers,size);
    cout << endl;
    displayArray(numbers,size);
    cout << endl;
    //initArray(numbers,size);
    cout << endl;
    int distrib[size];
    initArray(distrib,size);
    for(int i = 0; i < size; ++i){
        //distrib[numbers[i]] += 1;
        distrib[numbers[i]] = distrib[numbers[i]] + 1;
    }
    displayArray(distrib,size);
    cout << endl;
    return (0);

}
void initArray(int arr[], int size){
    for(int i = 0; i < size; ++i)
        arr[i] = 0;
}
