#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[300000+5], n, k;


ll solve(int pos, int ks) {

    //cout << "Called with " << pos << " " << ks << endl;
    if ((ks > 0 && pos >= n) || (ks <= 0 && pos < n)) return INT_MAX;
    if (pos == n || ks == 0) {
        return 0;
    }

    ll i, ans = INT_MAX;
    for (i = pos; i <= (n - ks); ++i) {
        ans = min(ans, solve(i + 1, ks - 1) + (arr[i] - arr[pos])); 
    }

    return ans;
}


int main() {

    //freopen("in.txt", "r", stdin);

    int i;
    scanf("%164d %I64d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &arr[i]);
        //cout << arr[i] << "endl";
    }
    //cout << endl;

    cout << solve(0, k) << endl;

    return (0);
}