
#include <iostream>
using namespace std;
enum weeks{sunday,monday,tuesday,wednesday,thursday,friday,saturday};
int main(){
    enum weeks today;
    today = tuesday;
    cout<<"The day in the week is: "<<today + 1<<endl;

    return (0);
}
