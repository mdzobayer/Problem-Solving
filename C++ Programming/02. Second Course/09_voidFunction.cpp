#include <iostream>
using namespace std;
void Heading(string name, string date){
    cout << "*************************************************" << endl;
    cout << "*  Name: " << name << "\t\t\t\t" << "*" << endl;
    cout << "*  Date: " << date << "\t\t\t\t" << "*" << endl;
    cout << "*************************************************" << endl;
}

int main(){
    string name, date;
    cout << "Enter Name and date: ";
    getline(cin,name);
    getline(cin,date);
    Heading(name,date);

    return (0);
}
