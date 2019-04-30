#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, value[15];
    string s;
    cin >> n >> s;

    for (i = 1; i < 10; ++i) {
        cin >> value[i];
    }
    int x, len = s.size() ;
    bool flag = true;

    for (i = 0; i < len; ++i) {
        x = s[i] - '0';
        if (value[x] > x) {
            s[i] = '0' + value[x];
            flag = false;
        }
        else if (value[x] == x && flag == false) {
            continue;
        }
        else if (flag == false) break;
    }
    cout << s << endl;

    return (0);
}