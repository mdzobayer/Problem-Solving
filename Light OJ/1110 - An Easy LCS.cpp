#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int length1, length2, dp[105][105];

int solve(int x, int y) {
    if (x >= length1 || y >= length2) return (0);

    if (dp[x][y] != -1) return dp[x][y];

    int ans = 0;

    if (s1[x] == s2[y]) {
        // printf("%c %c\n", s1[x], s2[y]);
        ans = max(ans, 1 + solve(x + 1, y + 1));
    }
    else {
        ans = max(ans, solve(x, y + 1));
        ans = max(ans, solve(x + 1, y));
    }
    
    ans = max(ans, solve(x + 1, y + 1));

    return dp[x][y] = ans;
}

vector < string > asendingOrder;

void PrintPath(string str, int x, int y, int ans) {
    //printf("Path str = %s x = %d y = %d ans = %d\n", str.c_str(), x, y, ans);
    if (ans == 0) {
        asendingOrder.push_back(str);
        return;
    }

    if (x >= length1 || y >= length2) return ;

    int atmp;
    atmp = solve(x, y);

    if (atmp == solve(x + 1, y + 1)) {
        PrintPath(str, x + 1, y + 1, ans);
    }
    else if (s1[x] == s2[y]) {
        PrintPath(str + s1[x], x + 1, y + 1, ans - 1);
    }
    else {
        PrintPath(str, x, y + 1, ans);
        PrintPath(str, x + 1, y, ans);
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, ans;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        cin.ignore();
        cin >> s1 >> s2;

        //cout << s1 << endl << s2 << endl;

        length1 = s1.size();
        length2 = s2.size();

        printf("Case %d: ", t);

        memset(dp, -1, sizeof(dp));

        ans = solve(0, 0);
        if (ans == 0) {
            puts(":(");
        }
        else {
            //printf("%d\n", ans);
            asendingOrder.clear();
            //cout << "Debug 1" << endl;
            PrintPath("", 0, 0, ans);
            //cout << "Debug 2" << endl;
            sort(asendingOrder.begin(), asendingOrder.end());
            printf("%s\n", asendingOrder[0].c_str());
        }
        
    }

    return (0);
}