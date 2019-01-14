#include<bits/stdc++.h>
using namespace std;

struct maxsort
{
    int m;
    int n;
};

bool operator <(maxsort a, maxsort b)
{
    if(a.m!=b.m)
    {
        return a.m >b.m ;
    }
    else
    {
       return a.n>b.n;
    }
}

int main()
{
    int test,i,j,t=1,n;
    scanf("%d",&test);
    int chk=0;
    while(t<=test)
    {
        /*
        if(chk)
        {
            printf("\n");
        }
        */
        scanf("%d",&n);
        vector<int>stocks;
        vector<maxsort>onlysort;
        int curmax=-1,curmaxindex;
        for(i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            stocks.push_back(m);
            maxsort tmp;
            tmp.m=m;
            tmp.n=i;
            onlysort.push_back(tmp);
        }
        sort(onlysort.begin(),onlysort.end());
        int takenindex=-1,currentindex=0;
        int maxvalue=-1;
        long long int profit=0;

        for(i=0;i<onlysort.size();i++)
        {
            maxvalue=onlysort[i].m;

            if(onlysort[i].n<=takenindex)
            {
                continue;
            }
            else
            {

                takenindex=onlysort[i].n;
                //cout<<maxvalue<<" "<<takenindex<<endl;
                while(currentindex<takenindex)
                {
                    //cout<<"currentindex="<<currentindex<<endl;
                    profit+=maxvalue-stocks[currentindex];
                    currentindex++;
                }
            }
        }

        printf("%lld\n",profit);
        chk++;
        t++;

    }

}
