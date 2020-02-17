
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

bool capitalized(string &s)
{
    //cout<<"S="<<s<<endl;
    ll ok=0;
    if(s[0]>='A'&& s[0]<='Z')
    {
        ok=1;
    }
    else
    {
        ok=0;
    }
    if(!ok)
        return false;
    ll i,j;
    for(i=1; i<s.size(); i++)
    {
        //cout<<"s[i]="<<s[i]<<endl;
        if(s[i]>='A' && s[i]<='Z')
        {
            //cout<<s<<" not capitalized"<<endl;
            return false;
        }
    }
    //cout<<s<<" capitalized"<<endl;
    return true;
}
bool haveStopper(string &s)
{
    //cout<<s<<" ";
    ll i,j;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='.'||s[i]==',')
        {
            //cout<<"have stopper"<<endl;
            return true;
        }
    }
    //cout<<"doesnt have stopper"<<endl;
    return false;
}


void Format(string &s)
{
    ll i;
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i]==','|| s[i]=='.')
        {
            if(s[i+1]!=' '){
                s.insert(s.begin()+i+1,' ');
                i++;
            }
        }
    }
}

int main()
{
//    freopen("abbreviation.in","r",stdin);
//    freopen("abbreviation.out","w",stdout);
    ll n,i,j,w=0;
    string s;
    while(getline(cin,s))
    {
        //Format(s);
        //cout<<s<<endl;
        w=0;
        vector<string>v;
        vector<string>abbr;
        string tmp;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]==' '||s[i]=='.'||s[i]==',' )
            {
                if(s[i]!=' ')
                 tmp.push_back(s[i]);
//                cout<<"w="<<w<<endl;
                //cout<<"tmp="<<tmp<<endl<<endl;
                if(capitalized(tmp) && tmp.size()>1 && haveStopper(tmp)==false)
                {
                    //cout<<"pushing "<<tmp<<endl;
                    abbr.push_back(tmp);
                }
                else
                {
                    char c=' ';
                    if(capitalized(tmp) && tmp.size()>1 && haveStopper(tmp))
                    {
                        //cout<<tmp<<" pushing to abbr"<<endl;
                        c=tmp[tmp.size()-1];
                        tmp.erase(tmp.begin()+tmp.size()-1);
                        abbr.push_back(tmp);
                        tmp="";
                    }
//                    cout<<"stooper or not valid str="<<tmp<<" abbr size="<<abbr.size()<<" w="<<w<<endl;
//                    cout<<"segemnt 3"<<endl;
                    if(w==1)
                        cout<<" ";
                    //cout<<"segement 2"<<endl;

                    if(abbr.size()>1)
                    {
                        w=1;
                        string abb="";
                        for(j=0; j<abbr.size(); j++)
                        {
                            abb.push_back(abbr[j][0]);
                        }
                        cout<<abb<<" (";
                        for(j=0; j<abbr.size(); j++)
                        {
                            cout<<abbr[j];
                            if(j<abbr.size()-1)
                                cout<<" ";
                        }
                        cout<<")";
                        if(tmp.size()>0)
                        {
                            cout<<" "<<tmp;
                        }
                        if(c!=' ')
                            cout<<c;
                    }
                    else
                    {
                        w=1;
                        //cout<<"segment 1"<<endl;
                        if(abbr.size())
                            cout<<abbr[0];
                        // if(tmp.size()>0 && abbr.size()>0)
                        //     cout<<" ";
                        cout<<tmp;
                        if(c!=' ')
                            cout<<c;
                    }
                    abbr.clear();
                }
                tmp="";
            }
            else
            {
                tmp.push_back(s[i]);
            }
        }
        //cout<<"tmp="<<tmp<<endl;
        if(tmp.size()>0|| abbr.size()>0)
        {
            if(capitalized(tmp) && tmp.size()>1 && haveStopper(tmp)==false)
            {
                if(w=1)
                    cout<<" ";
                abbr.push_back(tmp);
                w=1;
                string abb="";
                for(j=0; j<abbr.size(); j++)
                {
                    abb.push_back(abbr[j][0]);
                }
                cout<<abb<<" (";
                for(j=0; j<abbr.size(); j++)
                {
                    cout<<abbr[j];
                    if(j<abbr.size()-1)
                        cout<<" ";
                }
                cout<<")";
            }
            else
            {
                char c=' ';
                if(capitalized(tmp) && tmp.size()>1 && haveStopper(tmp))
                {
                    c=tmp[tmp.size()-1];
                    tmp.erase(tmp.begin()+tmp.size()-1);
                    abbr.push_back(tmp);
                    tmp="";
                }

                //cout<<"stooper or not valid str="<<tmp<<" abbr size="<<abbr.size()<<" w="<<w<<endl;
                if(w=1)
                    cout<<" ";

                if(abbr.size()>1)
                {
                    w=1;
                    string abb="";
                    for(j=0; j<abbr.size(); j++)
                    {
                        abb.push_back(abbr[j][0]);
                    }
                    cout<<abb<<" (";
                    for(j=0; j<abbr.size(); j++)
                    {
                        cout<<abbr[j];
                        if(j<abbr.size()-1)
                            cout<<" ";
                    }
                    cout<<")";
                    if(tmp.size()>0)
                    {
                        cout<<tmp;
                    }
                    if(c!=' ')
                        cout<<c;
                }
                else
                {
                    w=1;
                    if(abbr.size())
                        cout<<abbr[0];
                    // if(tmp.size()>0 && abbr.size()>0)
                    //     cout<<" ";
                    cout<<tmp;
                    if(c!=' ')
                        cout<<c;
                }
                abbr.clear();
            }
        }
        cout<<endl;
    }
}
