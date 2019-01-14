#include <iostream>
using namespace std;
int main(){
    /*
    for(int row = 1; row <= 5; ++row){
        for(int col = 1; col <= 5; ++col){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;

    for(int row = 1; row <= 5; ++row){
        for(int col = 1; col <=row; ++col){
            cout << "*";
        }
        cout << endl;
    }
    */

    for(int row = 1; row <= 5; ++row){
        for(int col = 1; col <= 5; ++col){
            cout << col << " * " << row << " = "
                 << row * col << "\t";
        }
        cout << endl;
    }
    return (0);
}
