#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void displayVector(vector<int> vect){
    for(int i = 0; i < vect.size(); ++i)
        cout << vect[i] << " ";

};

int main(){

    vector<int> numbers;
    srand((unsigned)time(NULL));
    int number;
    for(int i = 1; i <= 10000; ++i){
        number = rand() % 100 + 1;
        numbers.push_back(number);
    };
    cout << endl;
    displayVector(numbers);
    cout << endl;

    return (0);
};
