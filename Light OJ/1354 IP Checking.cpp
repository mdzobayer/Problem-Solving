#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, a, b, c, d, x, value, v[4], j;
    string s;
    bool flag;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        printf("Case %d: ", t);
        cin >> s;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '.')
                s[i] = ' ';
        }
        stringstream ss(s);
        ss >> v[0];
        ss >> v[1];
        ss >> v[2];
        ss >> v[3];
        cin >> s;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '.')
                s[i] = ' ';
        }
        stringstream ss1(s);
        j = 0;
        flag = true;
        while(ss1 >> s) {
            x = 1;
            value = 0;
            for (i = s.size() - 1; i >= 0; --i) {
                if (s[i] == '1') {
                    value += x;
                }
                x *= 2;
            }
            if (value != v[j]) {
                printf("No\n");
                flag = false;
                break;
            }
            ++j;
        }
        if (flag)
            printf("Yes\n");
    }

    return (0);
}
