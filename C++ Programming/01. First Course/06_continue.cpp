#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    while(i<=10){
        i++;
        if(i>3 && i<9)
            continue;
        cout<<i<<endl;
    }
    return (0);
}
