#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    int grade, total, count;
    double average = 0.0;
    total = 0; count = 0;
    string fileName;
    cout << "Enter path: ";
    getline(cin,fileName);
    ifstream inFile(fileName.c_str(), ios::in);
    if (!inFile){
        cout << "File not found!" << endl;
        exit(1);
    }
    while( !inFile.eof() ){
        inFile >> grade;
        total += grade;
        ++count;
        cout << grade << endl;
    }
    inFile.close();
    cout << "Total = " << total << endl;
    average = total / count;
    cout << "Average = " << average << endl;
    return (0);
}
