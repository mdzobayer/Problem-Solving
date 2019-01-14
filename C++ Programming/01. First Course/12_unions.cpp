#include <iostream>

using namespace std;
struct student{
    int age;
    char name[20];
};
union student1{
    int age;
    char name[20];
};
int main(){
    struct student str;
    union student1 uni;

    cout<<"Memory of struct = "<<sizeof(str)<<endl;
    cout<<"Memory of Unioun = "<<sizeof(uni)<<endl;

    return (0);
}
