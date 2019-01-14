#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    char x, y;
    int t, l = 1, n, m, k, cnt, foo, tho, ans, o, j, hun;
    cin >> t;
    cin.ignore();
    while(t--) {
        cnt = ans = o = 0;

        cin >> a >> m >> x >> n;
        cin.ignore();
        cin >> b >> j >> y >> k;
        if (a == "January" || ((a == "February") && m <= 29)) {
            n = n;
        }
        else {
            ++n;
        }
        if (b == "January" || ((b == "February") && j < 29)) {
            --k;
        }
        else {
           k = k;
        }

        foo = floor(((double) k) / 4) - ceil((((double)n) / 4)) + 1;
        hun = floor(((double) k) / 100) - ceil((((double)n) / 100)) + 1;
        tho = floor(((double) k) / 400) - ceil((((double)n) / 400)) + 1;
        ans = (foo + tho) - hun;

        printf("Case %d: %d\n", l++, ans);
    }

    return (0);
}
