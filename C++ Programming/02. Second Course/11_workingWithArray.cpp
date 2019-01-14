#include <iostream>

using namespace std;

int main(){
    /*const int size = 10;
    int numbers[size];
    numbers[0] = 1;
    numbers[1] = 2;
    for(int i = 2; i < size; ++i){
        numbers[i] = i + 1;
    }
    int total = 0;
    for(int i = 0; i < size; ++i){
        cout << i << ": " << numbers[i] << endl;
        total += numbers[i];
    }
    cout << "The total is: " << total << endl;
    const int size = 5;
    int grades[] = {100, 90, 80, 70, 60};
    int total = 0;
    double average;
    for(int i = 0; i < size; ++i)
        total += grades[i];
    average = total / size;
    cout << "The average grade is: " << average << endl;*/

    const int size = 3;
    char word[size] = {'t','h','e'};
    string rword;
    for(int i = size -1; i >= 0; --i)
        rword += word[i];
    cout << rword;

    return (0);
}
