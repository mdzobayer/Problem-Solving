#include <iostream>

using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the three values"<<endl;
    cin>>a>>b>>c;
    if(a>b){
        if(b>c)
            cout<<"a is greater";
    }
    if(b>c)
        cout<<"b is grater";
    else
        cout<<"c is grater";

    return (0);
}
