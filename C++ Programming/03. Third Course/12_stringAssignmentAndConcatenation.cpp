#include <iostream>
#include <string>

using namespace std;

int main() {

    string str0;       //Empty string [default constructor]
    string str1 = "";
    string str2(str1); //Copy constructor
    string str3("a string");
    string str4(10,'*');
    string str5 = "hello";
    string str6 = "World";
    string str7 = str5 + " " + str6 + "!"; //String Concatenation
    cout << str7 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str2 << endl;
    string str8 = "hello, " + str6 + ". " + "Zobayer";
    cout << str8 << endl;

    return (0);
}
