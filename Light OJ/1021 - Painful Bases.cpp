#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int

ll base, k, target, len, dp[(1 << 16) + 5][22];
string s;

ll baseXpower[18][16];

void generatePower(){
    ll i, j;
    for (i = 2; i < 17; ++i) {
        for (j = 0; j < 16; ++j) {
            if (j == 0) {
                baseXpower[i][j] = 1;
            }
            else if (j == 1) {
                baseXpower[i][j] = i;
            }
            else {
                baseXpower[i][j] = baseXpower[i][j - 1] * i;
            }
        }
    }
}

ll getValue(const char & ch) {
    if (ch == '0') return 0;
    else if(ch == '1') return (ll)1;
    else if(ch == '2') return (ll)2;
    else if(ch == '3') return (ll)3;
    else if(ch == '4') return (ll)4;
    else if(ch == '5') return (ll)5;
    else if(ch == '6') return (ll)6;
    else if(ch == '7') return (ll)7;
    else if(ch == '8') return (ll)8;
    else if(ch == '9') return (ll)9;
    else if(ch == 'A') return (ll)10;
    else if(ch == 'B') return (ll)11;
    else if(ch == 'C') return (ll)12;
    else if(ch == 'D') return (ll)13;
    else if(ch == 'E') return (ll)14;
    else if(ch == 'F') return (ll)15;
}

ll solve(int mask, int remainder) {
    if (mask == target) {
        return remainder == 0 ? 1 : 0;
    }

    if (dp[mask][remainder] != -1) {
        return dp[mask][remainder];
    }

    ll i, x, tmpValue = 1, j, power = 0, ans = 0;

    for (i = 0; i < len; ++i) {
        if ((mask & (1 << i)) == 0) {
            ++power;
        }
    }

    for (i = 0; i < len; ++i) {
        if ((mask & (1 << i)) == 0) {
            x = getValue(s[i]);

            x = ((baseXpower[base][power - 1] % k) * x) % k;

            ans += solve((mask | (1 << i)), x);
        }
    }

    return dp[mask][remainder] = ans;
}


int main() {

    freopen("in.txt", "r", stdin);

    int test, t, i, j;

    generatePower();

    // for (i = 2; i < 17; ++i) {
    //     for (j = 0; j < 16; ++j) {
    //         cout << baseXpower[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    

    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin >> base >> k;
        cin.ignore();
        cin >> s;
        
        len = s.size();
        target = ((1 << len) - 1);

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %llu\n", t, solve(0, 0));

    }

    return (0);
}