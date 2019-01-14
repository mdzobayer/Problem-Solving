#include <iostream>
using namespace std;
class oper{
public:
    int a = 0;
    void operator ++(){a=a+5;};
    void operator --(){a=a-5;};
    void display(){cout<<a<<endl;};
};
int main(){
    class oper app;
    app.a = 15;
    ++app;
    app.display();

    app.a = 25;
    -- app;
    app.display();

    return (0);
};
