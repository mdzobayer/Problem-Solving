#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    int len, i, cn = 1;
    cin >> s;
    len = s.size();
    for (i = 1; i < len; ++i) {
        if (s[i] == s[i - 1]) {
            ++cn;
        }
        else cn = 1;

        if (cn >= 7) {
            printf("YES\n");
            return (0);
        }
    }
    printf("NO\n");

    return (0);
}

