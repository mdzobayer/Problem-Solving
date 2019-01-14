#include <iostream>
using namespace std;

int main(){
    /*int num = 64;
    int *pnum;
    pnum = &num;
    cout << "UnDereferanced pointer: " << pnum << endl;
    cout << "Dereferanced pointer: " << *pnum << endl;

    //value directly assigned in the memory location
    *pnum = 65;
    cout << *pnum << endl;
    cout << num << endl;

    int num1 = 64;
    int num2 = 65;
    int *pnum1 = &num1;
    int *pnum2 = &num2;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "*pnum1: " << *pnum1 << endl;
    cout << "*pnum2: " << *pnum2 << endl;

    //memory location assigned but no value assignment
    pnum1 = pnum2;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "*pnum1: " << *pnum1 << endl;
    cout << "*pnum2: " << *pnum2 << endl;*/

    int num1 = 64;
    int num2 = 65;
        //C Programming like scanf() function
    int &rnum1 = num1;      //access memory location by reference
    int &rnum2 = num2;      //access memory location by reference

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "&rnum1: " << rnum1 << endl;
    cout << "&rnum2: " << rnum2 << endl;
    //Normal assignment and like c programming
    rnum1 = rnum2;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "&rnum1: " << rnum1 << endl;
    cout << "&rnum2: " << rnum2 << endl;

    return (0);

};
