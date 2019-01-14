#include <iostream>
#include <list>
using namespace std;

void display(list<int> lyst){
    list<int>::iterator iter = lyst.begin();
    while(iter != lyst.end()) {
        cout << *iter << endl;
        ++iter;
    };
};
void insertMax(list<int> &lyst, int value) {
    lyst.sort();
    int max = lyst.back();
    if(value > max) {
        lyst.push_back(value);
    }
}

int main() {
    list<int> numbers;
    cout << numbers.back() << endl;
    numbers.push_back(0);
    cout << numbers.back() << endl;
    int number;
    for(int i = 1; i <= 10; ++i) {
        cout << "Enter a number: ";
        cin >> number;
        insertMax(numbers, number);
    }
    display(numbers);

    return (0);
};
