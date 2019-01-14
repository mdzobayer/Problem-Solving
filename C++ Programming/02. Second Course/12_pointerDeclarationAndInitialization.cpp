#include <iostream>

using namespace std;

int main(){

    int *pNum = 0;
    int *pNum1, *pNum2;
    int *pNum3, pNum4;
    string *pFirst, pMiddle;
    int val = 64;
    int *pVal = &val;
    int *pVall = 0;
    int *pVal2 = pVal;
    cout << pVal << endl;
    cout << pVal2 << endl;
    return (0);
};
