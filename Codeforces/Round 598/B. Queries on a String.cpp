#include <bits/stdc++.h>


using namespace std;

int main() {

    int s_size, m, x, y, k, len;
    string s;
    cin >> s;
    s_size = s.size();
    cin >> m;
    while(m--) {
        cin >> x >> y >> k;
        --x, --y;
        len = y - x + 1;
        k %= len;
        cerr << s.substr(0, x) << ' ' << s.substr(y-k+1, k) << ' ' << s.substr(x, len - k) << ' ' << s.substr(y + 1, s_size - y) << endl;
        s = s.substr(0, x) + s.substr(y-k+1, k) + s.substr(x, len - k) + s.substr(y + 1, s_size - y);
    }
    cout << s << endl;

    return (0);
}
