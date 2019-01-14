#include <iostream>
using namespace std;

int square(int number){
    int squared = number * number;

    return squared;
    //return number * number;
}

int main(){
    int number, squared;
    cout << "Enter a number: ";
    cin >> number;
    //cout << number << " squared equals " << number * number << endl;
    //cout << number << " squared equals " << square(number) << endl;
    squared = square(number);
    cout << squared << endl;
    return (0);
};
