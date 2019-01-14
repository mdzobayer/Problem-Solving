#include <iostream>
#include <string>

using namespace std;

int main() {
    /*string s1 = "a needle in a haystack needle";
    int pos = s1.find("needle");
    if (pos >= 0) {
        cout << "found needle at position " << pos << endl;
    }
    else {
        cout << "no needle " << pos << endl;
    }

    string s2 = "a pin in a haystack pin";
    int pos1 = s2.rfind("pin");
    if (pos >= 0) {
        cout << "found pin at position " << pos1 << endl;
    }
    else {
        cout << "no pin " << pos1 << endl;
    }*/

    string numbers = "0123456789";
    string identifier = "name";
    int pos = identifier.find_first_of(numbers);
    if(pos >= 0) {
        cout << "illegal identifier " << pos << endl;
    }
    else {
        cout << "legal identifier" << endl;
    }

    return (0);
}
