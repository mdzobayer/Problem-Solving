#include <iostream>

int main()
{
    using namespace std;
    int a,b;
    a = 23;
    b = 10;
    cout<<"Values before swapping: "<<a<<" & "<<b<<endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<"Values after swapping: "<<a<<" & "<<b<<endl;

    return (0);
}
