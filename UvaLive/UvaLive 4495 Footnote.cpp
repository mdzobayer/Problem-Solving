#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

LLI limit, s, n, w, dp[505][505], a;

vector < int > pre[505];

void clearPreAndDp() {
    for (int i = 0; i < 505; ++i) {
        pre[i].clear();
    }

}

int findFootNote(LLI line, LLI target) {
    int Count = 0, i, len = target + line;
    bool rec[105];
    for (line; line < len ; ++line) {
        for (i = 0; i < pre[line].size(); ++i) {
            if (rec[pre[line][i]] == false) {
                rec[pre[line][i]] = true;
                ++Count;
            }
        }
    }
    return Count;
}

LLI solve(LLI line, LLI page) {
    //cout << "From rec " << line << " " << page << endl;
    cout << "";

    if (dp[line][page] != -1) {
        //cout << "From rec " << line << " " << page << " Back" << endl;
        return dp[line][page];
    }

    if (line == limit) {
        //cout << "I am base" << endl;
        int fooot;
        if ((fooot = findFootNote(line, 1)) + 1 > s)
            return INT_MAX;
        else
            return fooot;
    };

    LLI & ans = dp[line][page];

    ans = INT_MAX;
    //cout << ans << " ";

    int foot;

    for (int i = 1; ((i + (foot = findFootNote(line, i))) <= s) && (line + i <= limit); ++i) {
        ans = min(foot + solve(line + i, page + 1), ans);
    }

    return ans;
}

int main() {
    //FastRead

    fRead("in.txt");
    int t, test, i, j, cmtLine, cmtNumber;
    cin >> test;
    for (t = 1; t <= test; ++t) {
        clearPreAndDp();
        memset(dp, -1, sizeof(dp));

        cin >> limit >> s >> w;
        //cout << limit << " " << s << endl;
        for (i = 0; i < w; ++i) {
            cin >> cmtNumber;
            for (j = 0; j < cmtNumber; ++j) {
                cin >> cmtLine;
                pre[cmtLine].phb(i+1);
                //cout << cmtNumber << " " << cmtLine << endl;
            }
        }
        a = solve(1, 1);
        if (a == INT_MAX) a = -1;

        cout << "Case " << t << ": " << a << endl;
        //cout << "Unique cmt : " << findFootNote(1, 1) << endl;
    }

    return (0);
}
