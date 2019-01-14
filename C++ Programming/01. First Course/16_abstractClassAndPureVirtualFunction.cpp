#include <iostream>
using namespace std;
class shape{
protected:
    float l;
public:
    void get_data(){
        cin>>l;
    };
    virtual float area() = 0;
};
class square: public shape{
public:
    float area(){
        cout<<l*l<<endl;
        return (l * l);
    };
};
class circle: public shape{
public:
    float area(){
        cout<<3.14*l*l<<endl;
        return (3.14*l*l);
    };
};
int main(){
    class square sq;
    class circle ci;
    sq.get_data();
    sq.area();
    ci.get_data();
    ci.area();

    //cout<<sq.area()<<endl;


    return (0);

}
