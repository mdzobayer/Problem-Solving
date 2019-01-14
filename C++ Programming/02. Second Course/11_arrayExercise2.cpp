#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void buildArray(int arr[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
        arr[i] = rand() % 100 + 0;

}
void initArray(int arr[], int size){
    for(int i = 0; i < size; ++i)
        arr[i] = 0;
}
void displayArray(int arr[], int size){
   for(int i = 0; i < size; ++i)
        cout << i << ": " << arr[i] << endl;
}
void histogram(int arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << i << ": ";
        for(int j = 1; j <= arr[i]; ++j){
            cout << "*";
        }
        cout << endl;
    }
}
int main(){
    const int size = 101;
    int numbers[size];
    buildArray(numbers,size);
    cout << endl;
    histogram(numbers,size);
    int distrib[size];
    initArray(distrib,size);
    for(int i = 0; i < size; ++i){
        //distrib[numbers[i]] += 1;
        distrib[numbers[i]] = distrib[numbers[i]] + 1;
    }
    displayArray(distrib,size);
    cout << endl;
    histogram(distrib,size);
    cout << endl;
    return (0);

}

