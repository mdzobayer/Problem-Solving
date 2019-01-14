#include <iostream>
using namespace std;
int main(){
    int i,n,total,marks[100];
    cout<<"Enter the number of subject: ";
    cin>>n;
    for(i=0;i<=n-1;i++){
        cout<<"subject 0"<<i+1<<" = ";
        cin>>marks[i];
        total = total + marks[i];
    }
    cout<<"\n\n";
    cout<<"Total Marks = "<<total<<endl;
    cout<<"Average = "<<total/n<<endl;

    return (0);
}
