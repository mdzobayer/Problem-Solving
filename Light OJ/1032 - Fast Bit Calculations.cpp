#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool bits[35];
ll n, dp[35][3][35][3];

ll solve(int pos, bool pre, int cnt, bool flag) {
    if (pos < 0) return cnt;


    if (dp[pos][pre][cnt][flag] != -1) {
        return dp[pos][pre][cnt][flag];
    }

    ll & ans = dp[pos][pre][cnt][flag];

    ans = 0;

    int x = flag | bits[pos];

    for (int i = 0; i <= x; ++i) {
        ans += solve(pos - 1, i, cnt + (pre  && i), flag | (i < x));
    }
    return ans;
}

void toBinary() {
    memset(bits, false, sizeof(bits));


    int i = 0, pos, x = n;
    bool res;
    while(x > 0) {

        res = (x & 1);
        bits[i] = res;

        if (res) {
            pos = i;
        }
        x >>= 1;
        ++i;
    }
    //printf("Pos = %d\n", pos);
    memset(dp, -1, sizeof(dp));
    
    printf("%lld\n", solve(pos, 0, 0, 0));

}

int main() {

    int test, t;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        
        scanf("%lld", &n);

        printf("Case %d: ", t);
        toBinary();
    }
    

    return (0);
}