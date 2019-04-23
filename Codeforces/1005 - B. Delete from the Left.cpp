#include <bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;

    cin >> s1 >> s2;

    int x, y, z, minlen = min(s1.length(), s2.length());
    x = s1.length();
    y = s2.length();
    for(z = 0, --x, --y; minlen > 0; --minlen, --x, --y) {
        if (s1[x] == s2[y]) {
            ++z;
        }
        else break;
    }

    int ans = (s1.length() + s2.length()) - (z * 2);
    cout << ans << endl;

    return (0);
}