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
void curveGrades(int arr[], int size, int amount){
    for(int i = 0; i < size; ++i)
        arr[i] += amount;
}
int maxGrade(int arr[],int size){
    int maxValue = arr[0];
    int position = 0;
    for(int i = 0; i < size; ++i)
        if(arr[i] > maxValue){
            maxValue = arr[i];
            position = i;
        }
    return (position);
}
int minGrade(int arr[],int size){
    int minValue = arr[0];
    for(int i = 0; i < size; ++i)
        if(arr[i] < minValue)
            minValue = arr[i];

    return (minValue);
}

int main(){
    const int size = 10;
    int grades[size];
    buildArray(grades,size);
    displayArray(grades,size);
    cout << endl;
    //curveGrades(grades,size,5);
    displayArray(grades,size);
    cout << endl;
    //cout << "Maximum Value: " << maxGrade(grades,size) << endl;
    cout << "Minimum Value: " << minGrade(grades,size) << endl;
    int maxPosition = maxGrade(grades,size);
    cout << "The largest grade is "
         << grades[maxPosition] << endl;

    return (0);
}
