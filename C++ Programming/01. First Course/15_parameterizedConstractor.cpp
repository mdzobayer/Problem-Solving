#include <iostream>
using namespace std;
class xyz{
public:
    int a;
    xyz(int x){
        a = x;
    };
};
int main(){
    class xyz obj1(10);

    class xyz obj2(20);

    class xyz obj3(30);
    cout<<obj1.a<<endl<<obj2.a<<endl<<obj3.a<<endl;

    return (0);
};
