#include <iostream>

using namespace std;
int main(){
    int a[2][2];

    for(int i = 0;i < 2; i++){
        for(int j = 0;j < 2; j++){
            cout<<"a["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout<<endl;
    for(int i = 0;i < 2; i++){
        for(int j = 0;j < 2; j++){
            cout<<"a["<<i<<"]["<<j<<"]: "<<a[i][j]<<endl;
        }
    }
    return (0);
}
