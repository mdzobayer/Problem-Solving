
#include <iostream>

using namespace std;
int add(int num1,int num2);

int main()
{
    int a,b,c,d,sum;
    a = 10;
    b = 25;
    c = 1000;
    d = 3500;
    sum = 0;
    sum = add(a,b);
    cout<<sum;
    return (0);

}
int add(int num1,int num2){

    return (num1+num2);
}
