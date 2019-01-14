#include <iostream>
using namespace std;
int main(){
    int a=34;
    int *p;
    p = &a;
    cout<<"The value of a is : "<<*p<<endl;
    cout<<"The address of a is : "<<p<<endl;

    return (0);
}
