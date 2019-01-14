#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

int main() {
    string str[2000+5];
    int n, m, k, i, j, free;

    LLI Count = 0;
    cin >> n >> m >> k;

    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> str[i];
        //cout << str[i] << endl;
    }
    /// Check Horizontally
    for (i = 0; i < n; ++i) {
        free = 0;
        for (j = 0; j < m; ++j) {
            if (str[i][j] == '.') {
                //cout << "Here" << endl;
                ++free;
            }
            else {
                //cout << k << " " << free << endl;
                if (free >= k) {
                    Count += (free - k) + 1;
                }
                free = 0;
            }
        }
        if (free >= k) {
            Count += (free - k) + 1;
        }
        free = 0;
    }
    /// Check Vartically
    for (i = 0; i < m; ++i) {
        free = 0;
        for (j = 0; j < n; ++j) {
            if (str[j][i] == '.') {
                ++free;
            }
            else {
                if (free >= k) {
                    Count += (free - k) + 1;
                }
                free = 0;
            }
        }
        if (free >= k) {
            Count += (free - k) + 1;
        }
        free = 0;
    }
    if (k == 1) cout << Count / 2 << endl;
    else
        cout << Count << endl;

    return (0);
}
