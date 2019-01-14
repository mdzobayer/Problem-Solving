#include <iostream>

using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the three value";
    cin>>a>>b>>c;

    if(a > b && a > c)
        cout<<"a is the large number";
    else if(b > a && b > c)
        cout<<"b is the large number";
    else
        cout<<"c is the large number";

    return (0);
}
