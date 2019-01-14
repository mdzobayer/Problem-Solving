#include <iostream>
using namespace std;
class base{
public:
    void display(){cout<<"You are in the base class"<<endl;};
};
class derived: public base{
public:
    void display(){cout<<"You are in the derived class"<<endl;};

};
int main(){
    class base *b;
    class derived *d;
    b->display();
    d->display();

    return (0);
};
