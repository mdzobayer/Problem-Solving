#include <iostream>
using namespace std;
class printdata{
public:
    void print(int i){cout<<"Printing int: "<<i<<endl;};
    void print(double f){cout<<"Printing float: "<<f<<endl;};

};

int main(){
    class printdata pd;
    pd.print(4848);
    pd.print(55.55);

    return (0);
}
