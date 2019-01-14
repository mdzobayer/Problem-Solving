#include <iostream>
using namespace std;
int main()
{
    int a;
    cout<<"Enter 1 or 2: ";
    cin>>a;

    switch(a){
case 1:
    cout<<"You typed 1";
    break;
case 2:
    cout<<"you typed 2";
    break;
default:
    cout<<"you don't type 1 & 2. Try again";
    break;
    }

    return (0);
}
