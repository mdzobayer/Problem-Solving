#include <iostream>
using namespace std;
class base{
public:
    virtual void display(){cout<<"You are in the base class"<<endl;};
};
class derived: public base{
public:
    void display(){cout<<"You are in the derived class"<<endl;};

};
int main(){

    class derived d;
    class base *b = &d;

    b->display();


    return (0);
};

