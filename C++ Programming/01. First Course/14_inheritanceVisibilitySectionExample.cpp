#include <iostream>
using namespace std;
class base{
    int i,j;
public:
    void set(int a,int b){i = a; j = b;};
    void show(){cout<<i<<" "<<j<<endl;};
};
//Inheritance
class derived: public base{
    int k;
public:
    int intK(int x){k = x;return k;};
    //derived(int x){k = x;};
    void showK(){ cout<<k<<endl;};
};
int main(){
    class derived ob;
    //derived ob;
    //derived ob(4);
    ob.intK(4);
    ob.showK();
    ob.set(1,2);
    ob.show();

    return (0);
};
