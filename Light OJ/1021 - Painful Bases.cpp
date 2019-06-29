#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll base, k, target, len, dp[(1 << 16) + 5][22];
string s;

ll baseXpower[22][18][16];

void generatePower(){
    ll i, j, mod;
    for (mod = 1; mod < 21; ++mod) {
        //cout << "mod : " << mod  << endl;
        for (i = 2; i < 17; ++i) {
            for (j = 0; j < 16; ++j) {
                //cout << "i : " << i << " j : " << j << endl;
                if (j == 0) {
                    baseXpower[mod][i][j] = 1;
                }
                else if (j == 1) {
                    baseXpower[mod][i][j] = (i % mod);
                }
                else {
                    //cout << "Before Break" << endl;
                    baseXpower[mod][i][j] = (baseXpower[mod][i][j - 1] * i) % mod;
                    //cout << "After Break" << endl;
                }
            }
        }
    }
}

int getValue(const char & ch) {
    if (ch == '0') return 0;
    else if(ch == '1') return 1;
    else if(ch == '2') return 2;
    else if(ch == '3') return 3;
    else if(ch == '4') return 4;
    else if(ch == '5') return 5;
    else if(ch == '6') return 6;
    else if(ch == '7') return 7;
    else if(ch == '8') return 8;
    else if(ch == '9') return 9;
    else if(ch == 'A') return 10;
    else if(ch == 'B') return 11;
    else if(ch == 'C') return 12;
    else if(ch == 'D') return 13;
    else if(ch == 'E') return 14;
    else if(ch == 'F') return 15;
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

            x = ((baseXpower[k][base][power - 1] % k) * x) % k;
            x = (x + remainder) % k;
            ans += solve((mask | (1 << i)), x);
        }
    }

    return dp[mask][remainder] = ans;
}


int main() {

    //cout << "Debug 1" << endl;

    //freopen("in.txt", "r", stdin);

    int test, t, i, j;
    //cout << "Before generate" << endl;

    generatePower();

    //cout << "After generate" << endl;

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

        printf("Case %d: %lld\n", t, solve(0, 0));

    }

    return (0);
}