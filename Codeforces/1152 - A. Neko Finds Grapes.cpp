#include <bits/stdc++.h>

using namespace std;

int main() {

    int ans, x, i, n, m, evenChests, oddChests, evenKey, oddKey;

    ans = evenChests = oddChests = evenKey = oddKey = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x & 1) {
            ++oddChests;
        }
        else ++evenChests;
    }

    //cout << evenChests << " " << oddChests << endl;

    for (i = 0; i < m; ++i) {
        scanf("%d", &x);
        if(x & 1) {
            if (evenChests > 0) {
                ++ans;
                --evenChests;
            }
        }
        else {
            if (oddChests > 0) {
                ++ans;
                --oddChests;
            }
        }
    }
    printf("%d\n", ans);



    return (0);
}