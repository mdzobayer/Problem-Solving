#include <iostream>
using namespace std;
class base{
public:
    base(){cout<<"Constructing Base"<<endl;};

    virtual ~base(){cout<<"Destroying Base"<<endl;};
};
class derive: public base{
public:
    derive(){cout<<"Constructing Derive"<<endl;};
    ~derive(){cout<<"Destroying Derive"<<endl;};
};
int main(){
    base *baseptr = new derive;
    //base *baseptr = new derive();   //How it works ?? Don't understand
    delete baseptr;

    return (0);
}
