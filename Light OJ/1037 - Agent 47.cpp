#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int arr[20], n;
string s[20];

int target;

ll dp[65540];

ll bitmask(int mask) {
    //cout << "Entering " << mask << endl;
    if(mask == target) return (0);

    if(dp[mask] != -1) return dp[mask];
    int i, j, x, extra;
    ll ans = LLONG_MAX;

    for (i = 0; i < n; ++i) {
        //cout << "Debuging 1" << endl;
        if((mask & (1 << i))) {
            //cout << "Debugging 2" << endl;
            for (j = 0; j < n; ++j) {
                //cout << "Debugging 3" << endl;
                if(s[i][j] > '0' && (mask & (1 << j)) == 0) {
                    x = s[i][j] - '0';
                    if (arr[j] % x != 0) extra = 1;
                    else extra = 0;
                    x = arr[j] / x;
                    ans = min(ans, (extra + x) + bitmask(mask | (1 << j)));
                }
                else if((mask & (1 << j)) == 0) {
                    ans = min(ans, arr[j] + bitmask(mask | (1 << j)));
                }
            }
        }
        else {
            ans = min(ans, arr[i] + bitmask(mask | (1 << i)));
        }
    }
    //cout << ans << endl;
    return dp[mask] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, j, x;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        cin >> n;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        cin.ignore();

        for (i = 0; i < n; ++i) {
            cin >> s[i];
        }

        target = (1 << n) - 1;
        memset(dp, -1, sizeof(dp));
        //cout << target << endl;
        //cout << bitmask(0) << endl;

        printf("Case %d: %lld\n", t, bitmask(0));
    }

    return (0);
}
