
/*
ID: msdipu11
PROG: palsquare
LANG: C++14
*/

/*
timus
Your JUDGE_ID: 280608OK
*/
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu unsigned long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define vl vector<ll>
#define vll vector<vector<ll> >
#define vlu vector<llu>
#define vllu vector<vector<llu> >
#define pb              push_back
#define PI              acos(-1.0)
#define sc1(a)          scanf("%lld",&a)
#define sc2(a,b)        scanf("%lld %lld",&a,&b)
#define sc3(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define scd1(a)         scanf("%llf",&a)
#define scd2(a,b)       scanf("%llf %llf",&a,&b)
#define scd3(a,b,c)     scanf("%llf %llf %llf",&a,&b,&c)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(ll i=a;i<=b;i++)
#define ROF(i,a,b)      for(ll i=a;i>=b;i--)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
struct st
{
    ll s,e,id;
};
bool operator <(st a,st b)
{
    if(a.e!=b.e)
        return a.e>b.e;
    return false;
}

ll t;
void Topsort(ll node,vll &connection, vl &startTime,vl &endtime,vector<st>&timer,vl &vis)
{
    ll i,j,nxt;
    startTime[node]=t;
    t++;

    for(i=0;i<connection[node].size();i++)
    {
        nxt=connection[node][i];
        if(vis[nxt]!= 1)
        {
            vis[nxt]=1;
            Topsort(nxt,connection,startTime,endtime,timer,vis);
        }
    }
    endtime[node]=t;
    t++;
    //endtime[node]=t;
    timer[node].s=startTime[node];
    timer[node].e=endtime[node];
    return;
}


///finds which i cant learn
ll countChild;
void SCC(ll node,ll root,vl &parent, vl &cantlearn, vll &Rconnection,vl &vis)
{

    ll i,j,nxt;
    for(i=0;i<Rconnection[node].size();i++)
    {
        nxt=Rconnection[node][i];
        if(!vis[nxt])
        {
            vis[nxt]=1;
            parent[nxt]=root;
            countChild++;
            SCC(nxt,root,parent,cantlearn,Rconnection,vis);
        }
    }
    if(countChild>1)
        cantlearn[node]=1;
    return;
}

void cantlearnNodes(ll node ,vll &connection,vl &vis, vl &cantlearn)
{
    ll i,j,nxt;
    for(i=0;i<connection[node].size();i++)
    {
        nxt=connection[node][i];
        if(!vis[nxt])
        {
            vis[nxt]=1;
            cantlearn[nxt]=1;
            cantlearnNodes(nxt,connection,vis,cantlearn);
        }
    }
    return;
}

void Order(ll node, ll mask, vll &connection,vl &cantlearn,vl &requirement,vl &vis)
{
    ll i,j,nxt;
    for(i=0;i<connection[node].size();i++)
    {
        nxt=connection[node][i];
        if(vis[nxt] && cantlearn[node]==0)
        {
            vis[nxt]=0;
            Order(nxt,(mask|(1<<node)),connection,cantlearn,requirement,vis);
        }
    }
    requirement[node]|=mask;
    return;
}

ll solve(ll day,ll mask,ll n,vl &cantlearn,vl &cost, vl&requirements,vll &memory)
{
    if(day>n)
        return 0;

    if(memory[day][mask]!=-1)
        return memory[day][mask];
    ll res=0,i;
    for(i=0;i<n;i++)
    {
        if((mask&(1<<i))==0 && cantlearn[i]==0 && (requirements[i]&mask)==requirements[i])
        {
            ll tmp=solve(day+1,(mask|(1<<i)),n,cantlearn,cost,requirements,memory)+cost[i]*day;
            res=max(res,tmp);
        }
    }
    return memory[day][mask]=res;
}

ll u,v;
ll findUandV(string &s,map<string,ll>&mp,ll l)
{
    string tmp1="",tmp2="";
    ll i,j;
    for(i=0;i<s.size();i++)
    {
        if(s[i+1]=='-')
            break;
        tmp1.push_back(s[i]);
    }
    //cout<<"tmp1="<<tmp1<<endl;
    for(j=i+5;j<s.size();j++)
    {
        tmp2.push_back(s[j]);
    }
    //cout<<"tmp2="<<tmp2<<endl;

    u=mp[tmp1];
    v=mp[tmp2];
    //cout<<"u="<<u<<" v="<<v<<endl;
    return l;
}

ll input(string &s,string &name)
{
    ll i,j,last,cost=0;

    for(i=0;i<s.size();i++)
    {
        if(s[i+1]>='0' && s[i+1]<='9')
        {
            last=i+1;
            break;
        }
        name.push_back(s[i]);
        //cout<<"name="<<name<<endl;
    }
    //cout<<"last="<<last<<" sz="<<s.size()<<endl;
    for(i=last;i<s.size();i++)
    {
        cost*=10;
        cost+=s[i]-'0';
        //cout<<"i="<<i<<" cost="<<cost<<endl;
    }
    return cost;
}

int main()
{

    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    ll test,n,m;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        string s;
        ll i,j,l=1;
        map<string,ll>mp;
        vl cost(n+10);
        vll connection(n+10);
        vll rconnection(n+10);
        cin.ignore();
        for(i=1;i<=n;i++)
        {
            string s,name;
            j=0;
            //cout<<"here"<<endl;
            getline(cin,s);
            //cout<<"s="<<s<<endl;
            j=input(s,name);
            //cout<<"name="<<name<<" j="<<j<<endl;
            mp[name]=l;
            cost[l]=j;
            //cout<<"id="<<mp[name]<<endl;
            l++;
        }
        for(i=1;i<=m;i++)
        {
            getline(cin,s);
            l=findUandV(s,mp,l);
            //cout<<"u="<<u<<" v="<<v<<endl;
            connection[u].push_back(v);
            rconnection[v].push_back(u);
        }
        //cout<<"input done"<<endl;
        vector<ll>vis1(n+10,0);
        vector<ll>vis2(n+10,0);
        vector<ll>vis3(n+10,0);
        vector<ll>vis4(n+10,0);
        vector<ll>start(n+10,0);
        vector<ll>eending(n+10,0);
        vector<ll>parent(n+10,0);
        vector<ll>cantlearn(n+10,0);
        vector<ll>requirement(n+10,0);
        //cout<<"here"<<endl;
        vector<ll>col(((1<<((n+1)))-1),-1);
        //cout<<"here1"<<endl;
        vector<vector<ll> >memory(20,col);
        //cout<<"here2"<<endl;
        vector<st>timer(n+1);
        timer[0].id=0;
        timer[0].e=2e9;
        for(i=1;i<=n;i++)
        {
            cout<<"i="<<i<<endl;
            st tmp;
            tmp.id=i;
            timer[i].id=tmp.id;
        }
        //cout<<"init done"<<endl;
        t=0;
        for(i=1;i<=n;i++)
        {
            if(vis1[i]==0)
            {
                vis1[i]=1;
                Topsort(i,connection,start,eending,timer,vis1);
            }
        }
        //cout<<"topsort done"<<endl;
        SORT(timer);
        for(i=1;i<=n;i++)
        {
            ll cur=timer[i].id;
            if(vis2[cur]==0)
            {
                vis2[cur]=1;
                countChild=1;
                SCC(cur,cur,parent,cantlearn,rconnection,vis2);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(vis3[i]==0 && cantlearn[i]==1)
            {
                countChild=1;
                vis3[i]=1;
                cantlearnNodes(i,connection,vis1,cantlearn);
            }
        }
        for(i=1;i<timer.size();i++)
        {
            ll cur=timer[i].id;
            if(vis4[cur]==0 && cantlearn[cur]==0)
            {
                vis4[cur]=1;
                Order(cur,0,connection,cantlearn,requirement,vis4);
            }
        }
        ll res=solve(1,0,n,cantlearn,cost,requirement,memory);
        cout<<res<<endl;
    }
}
