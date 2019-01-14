#include <iostream>
using namespace std;
class xyz{
public:
    int a;
    int b;
    xyz(){
    a = 20;
    b = 30;
    };
};
int main(){
    class xyz obj;
    cout<<obj.a<<endl<<obj.b<<endl;

    return (0);
};
