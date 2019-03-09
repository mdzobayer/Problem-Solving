
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;
    int i, len, mn;
    cin >> s1 >> s2;
    len = s1.size();
    for (i = 0; i < len; ++i) {
        s1[i] = tolower(s1[i]);
    }
    len = s2.size();
    for (i = 0; i < len; ++i) {
        s2[i] = tolower(s2[i]);;
    }

    mn = s1.compare(s2);

    if(mn < 0) {
        cout << -1 << endl;
    }
    else if (mn > 0) {
        cout << 1 << endl;
    }
    else cout << 0 << endl;

    return (0);
}
