#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int cnt = 0, cnt2 = 0, i, len;
    string s;
    cin >> s;
    len = s.size();
    for (i = 0; i < len; ++i) {
        cnt += s[i] - '0';
    }

    for (i = len - 1; i >= 0; --i) {
        cnt2 += min((s[i] - '0'), ('9' - s[i] + 1));
    }
    //cout << cnt << " " << cnt2 << endl;
    cout << min(cnt, cnt2) << endl;


    return (0);
}