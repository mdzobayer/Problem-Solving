
#include <iostream>
//using namespace std;

namespace foo{
    int value(){return (5);};
};
namespace bar{
    const double pi = 3.1415;
    double value(){ return (2*pi);};
};

using namespace bar;

int main(){
    std::cout<<foo::value()<<'\n';
    std::cout<<bar::value()<<'\n';
    std::cout<<pi<<'\n';

    return (0);
};
