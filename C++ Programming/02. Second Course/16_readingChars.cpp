#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char c;
    int count = 1;
    ifstream inFile("c:\\data\\chars.txt", ios::in);
    inFile.get(c);
    while(!inFile.eof()){
        cout << c;
        if (c == 'e')
            ++count;
        inFile.get(c);
    }
    cout << endl << endl;
    cout << "There are " << count
         << " es in the file. " << endl;
    inFile.close();
    return (0);
}
