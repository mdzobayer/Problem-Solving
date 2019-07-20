#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll minCost[130][130];

void Init() {
    int i, j;
    for (i = 0; i < 130; ++i) {
        for (j = 0; j < 130; ++j) {
            if (i == j) {
                minCost[i][j] = 0;
            }
            else {
                minCost[i][j] = INT_MAX;
            }
        }
    }
}


int main() {

    //freopen("in.txt", "r", stdin);

    ll m, i, j, c, k;
    char a, b;
    string s1, s2;


    while(cin >> s1 >> s2) {
        Init();
        //memset(minCost, -1, sizeof(minCost));
        //cout << "Input: " << s1 << " " << s2 << endl;

        cin >> m;
        //cin.ignore();
        for (i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            //cout << a << " " << b << " " << c << endl;
            minCost[a][b] = min(minCost[a][b], c);
        }

        for (i = 33; i <= 126; ++i) {
            for (j = 33; j <= 126; ++j) {
                for (k = 33; k <= 126; ++k) {
                    minCost[j][k] = min(minCost[j][k], minCost[j][i] + minCost[i][k]);
                }
            }
        }

        ll cost, len = s1.size();
        cost = 0;
        bool flag = false;

        for (i = 0; i < len; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            else if (minCost[s1[i]][s2[i]] == INT_MAX) {
                flag = true;
                break;
            }
            else {
                cost += minCost[s1[i]][s2[i]];
            }
        }

        if (flag) {
            puts("-1");
        }
        else {
            cout << cost << endl;
        }
    }

    return (0);
}
