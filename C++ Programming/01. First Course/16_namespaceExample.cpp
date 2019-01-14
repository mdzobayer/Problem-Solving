#include <iostream>
using namespace std;

namespace first_space{
    void func(){
        cout<<"Inside first_space"<<endl;
    };
};
namespace second_space{
    void func(){
        cout<<"Inside second_space"<<endl;
    };
};

using namespace first_space;
int main(){
    func(); //automatically using namespace
    second_space::func(); //manually using namespcae

    return (0);
};
