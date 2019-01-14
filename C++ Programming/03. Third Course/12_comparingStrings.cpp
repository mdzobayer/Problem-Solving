#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1 = "clean";
    string s2 = "clear";
    if(s1 > s2) {
        cout << s1 << " is grater than " << s2 << endl;
    }
    else {
        cout << s2 << " is grater than " << s1 << endl;
    }
    cout << endl;
    cout << s1.compare(s2) << endl;
        /*
           Compare result 1 means s1 is grater than s2
           Compare result 0 means s1 equal s2
           Compare result -1 means s1 is less then s2
        */

    return (0);
}
