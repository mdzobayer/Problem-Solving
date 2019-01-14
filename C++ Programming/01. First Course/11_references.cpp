#include <iostream>
using namespace std;

int main(){
    int a = 30;
    int& b = a;
    cout<<a<<endl;
    b = 45;
    cout<<a<<endl;
    a = 99;
    cout<<b<<endl;
    cout<<a<<endl;

    return (0);
}
