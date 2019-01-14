#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vec vector< ll >

ll max(ll a, ll b) { return (a > b)? a : b; }


ll knapSack(ll W, vec &wt, vec &val, ll n)
{

   ll i, w;
   ll K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    vec val;
    vec wt;
    ll W, n, i, x, y;
    cin >> W >> n;

    for (i = 0; i < n; ++i) {
        cin >> x >> y;
        val.push_back(y);
        wt.push_back(x);
    }

    printf("%d\n", knapSack(W, wt, val, n));

    return 0;
}
