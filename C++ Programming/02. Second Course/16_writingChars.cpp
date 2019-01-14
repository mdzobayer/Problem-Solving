#include <iostream>
#include <fstream>

using namespace std;

int main(){

    char c;
    /*c = 'a';
    ofstream outFile("c:\\data\\chars.txt", ios::out);
    outFile.put(c);
    outFile.put('Z');
    outFile.put('L');
    outFile.close();*/
    ofstream outFile("c:\\data\\chars.txt", ios::out);
    while (cin >> c){
        outFile.put(c);
    }
    outFile.close();
    return 0;
}
