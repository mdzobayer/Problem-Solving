#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, x;
    bool have[200000+5];
    memset(have, false, sizeof(have));

    scanf("%d", &n);
    for (i = 1; i < n; ++i) {
        scanf("%d", &x);
        have[x] = true;
    }

    for (i = 1; i <= n; ++i) {
        if (have[i] == false) {
            cout << i << endl;
            break; 
        }
    }


    return (0);
}