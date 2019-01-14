#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outFile("c:\\data\\grades.txt", ios::out);
    outFile << 100 << endl;
    outFile << 90 << endl;
    outFile << 80 << endl;
    outFile << 70 << endl;
    /*int grade;
    for(int i = 1; i < 6; ++i){
        cout << "Enter a grade: ";
        cin >> grade;
        outFile << grade << endl;
    }*/
    outFile.close();
    cout << "All finished. " << endl;
    return (0);
}
