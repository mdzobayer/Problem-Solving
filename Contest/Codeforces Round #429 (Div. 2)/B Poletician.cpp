#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    unsigned long long int total=0;
    bool odd=0;
    scanf("%d",&n);
    vector<int>number;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        number.push_back(j);
        if(j%2==1)
        {
            odd=1;
        }
        total+=j;
    }
    if(total%2==0)
    {
        if(odd)
        {
            cout<<"First"<<endl;
        }
        else
            cout<<"Second"<<endl;
    }
    else
        cout<<"First"<<endl;
}
