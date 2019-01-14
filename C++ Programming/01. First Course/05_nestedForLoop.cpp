#include <iostream>

using namespace std;
int main()
{
    int n;
    //cout<<"Enter any integer: ";
    //cin>>n;
    for(n=1;n<=10;n++){
    for(int i=1;i<=10;i++){
        cout<<""<<n<<" * "<<i<<" = "<<i*n<<endl;
    }
    cout<<'\n';
    }
    return (0);
}
