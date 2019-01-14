#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double month1,month2,month3,month4;
    month1 = 1061.2363;
    month2 = 1073.47;
    month3 = 1071.6378;
    month4 = 1069.736;

    cout << setprecision(10);

    cout << "Month" << "\t" << "Reading" << endl;
    cout << "    " << 1 << "\t" << month1 << endl;
    cout << "    " << 2 << "\t" << month2 << endl;
    cout << "    " << 3 << "\t" << month3 << endl;
    cout << "    " << 4 << "\t" << month4 << endl;

    int fieldLenght = 15;
    cout << endl << endl <<endl;
    cout << setw(5) << "Month" << setw(fieldLenght)
         << "Reading" << endl << endl;
    cout << setw(5) << 1 << setw(fieldLenght) << month1 << endl;
    cout << setw(5) << 2 << setw(fieldLenght) << month2 << endl;
    cout << setw(5) << 3 << setw(fieldLenght) << month3 << endl;
    cout << setw(5) << 4 << setw(fieldLenght) << month4 << endl;

    return (0);
};
