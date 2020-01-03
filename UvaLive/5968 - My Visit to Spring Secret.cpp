#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    string s;
    int test, t, i, spring, len, winter;
    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; ++t) {
        cin >> s;
        spring = winter = 0;
        len = s.size();
        --len;
        for (i = 0; i < len; ++i) {
            if (s[i] == 'S' && s[i + 1] == 'S') {
                ++spring;
            }
            else if (s[i] == 'S') {
                ++winter;
            }
        }

        printf("Case %d: %d / %d\n", t, spring, winter);
    }

    return (0);
}