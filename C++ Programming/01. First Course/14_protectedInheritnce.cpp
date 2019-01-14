#include <iostream>
using namespace std;
class base{
private:
    int i;
protected:
    int j;
public:
    int k;
    void seti(int a){i = a;};
    int geti(){return i;};
};
class derived: protected base{
public:
    void setj(int a){ j = a;};
    void setk(int a){ k = a;};
    int getj(){return j;};
    int getk(){return k;};
};

int main(){
    class derived ob;
    ob.setk(10);
    cout<<ob.getk()<<endl;
    ob.setj(12);
    cout<<ob.getj()<<endl;

    return (0);
}

