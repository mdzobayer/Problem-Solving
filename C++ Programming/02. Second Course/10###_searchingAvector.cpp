#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void buildVector(vector<int> &vect){
    srand((unsigned)time(NULL));
    for(int i = 1; i <= 10; ++i){
        vect.push_back(rand() % 1000 + 1);
    }
}
int searchVector(vector<int> vect, int value){
    /*for(int i = 0; i < vect.size(); ++i){
        if(vect[i] == value)
            return i;
    }
    return (-1);*/
    int found = -1;
    found = vect.at(value);
    return (found);

}
void displayVector(vector<int> vect){
    for(int i = 0; i < vect.size(); ++i){
        cout << vect[i] << " ";
    }
    cout << endl;
}
int main(){

    vector<int> numbers;
    buildVector(numbers);
    displayVector(numbers);
    int found, item;
    cout << "Enter a value to search for: ";
    cin >> item;
    found = searchVector(numbers,item);
    //found = numbers.at(item);
    if(found == -1){
        cout << "Didn't find item in vector."
             << endl;
    }
    else
        cout << "Found the item at vector position: "
             << found << endl;

    return (0);
}
