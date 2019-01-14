
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=1e5+5;

int a[maxn],b[maxn],c[maxn];
int n,k;

void add(int i,int v,int * a) {
    while(i<=n) {
        a[i]+=v;
        i+=i&-i;
    }
}

int sum(int i,int *a) {
    int res=0;
    while(i>0) {
        res+=a[i];
        i-=i&-i;
    }
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d",&n,&k)) {
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        int x,y;
        for(int i=1; i<=n; i++) {
            scanf("%d",&x);
            if(x<0)  add(i,1,a);
            if(x==0) add(i,1,b);
            c[i]=x;
        }
        char s[5];
        for(int i=0; i<k; i++) {
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='C') {
                if(y==0) {
                    if(c[x]==0)continue;
                    add(x,1,b);
                    if(c[x]<0)add(x,-1,a);
                    c[x]=y;
                    continue;
                } else {
                    if(c[x]==0)      add(x,-1,b);
                    if(y<0&&c[x]>=0) add(x,1,a);
                    if(y>0&&c[x]<0)  add(x,-1,a);
                    c[x]=y;
                }
            } else {
                int has_0=sum(y,b)-sum(x-1,b);
                char c;
                if(has_0) c='0';
                else {
                    int num=sum(y,a)-sum(x-1,a);
                    c=num&1?'-':'+';
                }
                putchar(c);
            }
        }
        putchar(10);
    }
    return 0;
}
