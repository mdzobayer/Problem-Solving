#include <bits/stdc++.h>

#define MX_GROUP 1005

using namespace std;

int dp[MX_GROUP][30], k, avaliableG;
bool groups[MX_GROUP][30];


int solve(int cGroup, int preChar) {
    if (cGroup < 0) return (0);


    // DP task
    if(dp[cGroup][preChar] != -1) return dp[cGroup][preChar];

    int i, j, uc = 0, ans2, ans1;

    for (i = 0; i < 26; ++i) {
        if (groups[cGroup][i])
            ++uc;
    }

    ans2 = INT_MAX;

    for (i = 0; i < 26; ++i) {
        if (!groups[cGroup][i]) continue;
        

        ans1 = uc;
        //if(i == preChar) --ans1;

        for (j = 0; j < 26; ++j) {
            if (!groups[cGroup][j]) continue;
            if (i == j && uc > 1) continue;

            if(ans1 > 1) {
                if (i == preChar) {
                    ans2 = min(ans2, solve(cGroup - 1, j) + ans1 - 1);
                }
                else {
                    ans2 = min(ans2, solve(cGroup - 1, j) + ans1);
                }
            }
            else {
                if (i == preChar) {
                    ans2 = min(ans2, solve(cGroup - 1, preChar));
                }
                else {
                    ans2 = min(ans2, solve(cGroup - 1, j) + 1);
                }
            }

            // if (i != j)
            //     ans2 = min(ans2, solve(cGroup - 1, j) + ans1);
            // else if(preChar == j) {
            //     ans2 = min(ans2, solve(cGroup - 1, j));
            // }
            // else {
            //     ans2 = min(ans2, solve(cGroup - 1, j) + ans1);
            // }
        }
    }

    return dp[cGroup][preChar] = ans2;
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, i, t, len, index, ans;
    string s;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        s = "";

        scanf("%d", &k);
        cin >> s;

        memset(groups, false, sizeof(groups));
        avaliableG = 0;
        len = s.length();
        //cerr << "k = " << k << endl;
        for (i = 0; i < len; ++i) {
            index = (int)i / k;
            //cerr << index << " ";
            groups[index][s[i]-'a'] = true;
        }
        //cerr << endl;
        avaliableG = index;
        memset(dp, -1, sizeof(dp));

        ans = solve(avaliableG, 26);
        cout << ans << endl;
    }
    
    return (0);
}