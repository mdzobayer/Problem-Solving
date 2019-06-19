#include <bits/stdc++.h>

using namespace std;

struct State {
    int value = 0;
    string str = "";
};

string s1, s2;
int length1, length2;
State dp[105][105];

State solve(int x, int y) {
    if (x >= length1 || y >= length2) {
        State tmp;
        return tmp;
    }

    if (dp[x][y].value != -1) return dp[x][y];

    State ans;

    if (s1[x] == s2[y]) {
        // printf("%c %c\n", s1[x], s2[y]);
        if (ans.value < 1 + solve(x + 1, y + 1).value) {
            ans = solve(x + 1, y + 1);
            ++ans.value;
            ans.str = s1[x] + ans.str;
        }
    }
    else {
        if (ans.value < solve(x, y + 1).value) {
            ans = solve(x, y + 1);
        }
        else if (ans.value == solve(x, y + 1).value) {
            ans.str = min(ans.str, solve(x, y + 1).str);
        }

        if (ans.value < solve(x + 1, y).value) {
            ans = solve(x + 1, y);
        }
        else if (ans.value == solve(x + 1, y).value) {
            ans.str = min(ans.str, solve(x + 1, y).str);
        }
    }


    if (ans.value < solve(x + 1, y + 1).value) {
        ans = solve(x + 1, y);
    }
    else if (ans.value == solve(x + 1, y + 1).value) {
        ans.str = min(ans.str, solve(x + 1, y).str);
    }

    return dp[x][y] = ans;
}


int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, j;
    State ans;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        cin.ignore();
        cin >> s1 >> s2;

        //cout << s1 << endl << s2 << endl;

        length1 = s1.size();
        length2 = s2.size();

        printf("Case %d: ", t);

        for (i = 0; i < 105; ++i) {
            for (j = 0; j < 105; ++j) {
                dp[i][j].value = -1;
                dp[i][j].str = "";
            }
        }

        ans = solve(0, 0);
        if (ans.value == 0) {
            puts(":(");
        }
        else {
            printf("%s\n", solve(0, 0).str.c_str());
        }

    }

    return (0);
}
