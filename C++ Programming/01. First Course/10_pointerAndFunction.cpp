#include <iostream>
using namespace std;
void swap(int *num1,int *num2);

int main(){
    int a = 3;
    int b = 33;
    cout<<a<<"\t"<<b<<endl;
    swap(&a,&b);
    cout<<a<<"\t"<<b<<endl;
    return (0);
}
void swap(int *num1,int *num2){

    int num3;
    num3 = *num1;
    *num1 = *num2;
    *num2 = num3;

}
