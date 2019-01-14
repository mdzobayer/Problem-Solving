#include <iostream>
using namespace std;
int main()
{
    double number,factorial = 1;
    cout<<"Enter any number: ";
    cin>>number;
    while(number>0){
        factorial = factorial * number;
        --number;
    }
    cout<<factorial<<endl;
    return (0);
}
