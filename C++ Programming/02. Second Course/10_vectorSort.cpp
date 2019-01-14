#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void buildVector(vector<int> &vect, int numItems){
    srand(time(NULL));
    for(int i = 1; i <= numItems; ++i)
        vect.push_back(rand() % 1000 + 1);
}

void displayVector(vector<int> vect){
    for(int i = 0; i < vect.size(); ++i)
        cout << vect[i] << endl;
}
void displayVectorS(vector<string> vect){
    for(int i = 0; i < vect.size(); ++i)
        cout << vect[i] << endl;
}

int main(){

    /*vector<int> numbers;
    buildVector(numbers,100000);
    displayVector(numbers);
    cout << endl;
    sort(numbers.begin(), numbers.end());
    displayVector(numbers);
    cout << endl;*/

    vector<string> names;
    names.push_back("Raymond");
    names.push_back("Cynthia");
    names.push_back("David");
    names.push_back("William");
    names.push_back("Mike");
    displayVectorS(names);
    cout << endl;
    sort(names.begin(),names.end());
    displayVectorS(names);
    cout << endl;

    return (0);
}
