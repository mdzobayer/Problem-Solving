#include <iostream>

using namespace std;

int main(){
    int a[5];
    cout<<"Enter any 5 random integer: "<<endl;
    for(int i = 0;i<=4;i++){
        cout<<"a["<<i+1<<"]: ";
        cin>>a[i];
    }
    cout<<endl;
    cout<<endl;
    for(int j = 0; j <= 4; j++){
        cout<<"a["<<j+1<<"]: "<<a[j]<<endl;
    }

    return (0);
}
