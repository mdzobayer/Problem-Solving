#include <iostream>
#include <vector>

using namespace std;

struct subject {
    string name;
    int marks;
    int credits;
};


int main() {
    vector<subject> sub;

    //Push back new subject created with default constructor.
    sub.push_back(subject());

    //Vector now has 1 element @ index 0, so modify it.
    sub[0].name = "english";
    sub[0].marks = 85;
    sub[0].credits = 25;
    cout << sub[0].name << endl;
    cout << sub[0].marks << endl;
    cout << sub[0].credits << endl;

    //Add a new element if you want another:
    sub.push_back(subject());

    //Modify its name and marks.
    sub[1].name = "math";
    sub[1].marks = 90;
    sub[1].credits = 35;
    cout << sub[1].name << endl;
    cout << sub[1].marks << endl;
    cout << sub[1].credits << endl;

    return (0);
}
