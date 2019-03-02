#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector < pair < int, pair <int, int> > > vt;

int cArray[200000+5];

int main() {
    //freopen("in.txt", "r", stdin);

    int k, seq, n, i, len;
    int total, x, y;

    scanf("%d", &k);
    for (seq = 1; seq <= k; ++seq) {
        scanf("%d", &n);
        total = 0;

        for (i = 0; i < n; ++i) {
            scanf("%d", &cArray[i]);
            total += cArray[i];
        }
        for (i = 0; i < n; ++i) {
            vt.push_back(make_pair(total - cArray[i], make_pair(seq, i+1)));
        }
    }

    stable_sort(vt.begin(), vt.end());
    len = vt.size();
    for (i = 0; i < len - 1; ++i) {
        if(vt[i].first == vt[i + 1].first) {
            if(vt[i].second.first != vt[i + 1].second.first) {
                cout << "YES" << endl;
                cout << vt[i].second.first << " " << vt[i].second.second << endl;
                cout << vt[i + 1].second.first << " " << vt[i + 1].second.second << endl;
                return (0);
            }
        }
    }


    cout << "NO" << endl;

    return (0);
}
