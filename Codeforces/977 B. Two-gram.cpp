#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, i, c = 1;
    string s, tmp;
    map < string, int > mp;

    cin >> n >> s;

    for (i = 0; i < n - 1; ++i) {
        tmp = "";
        tmp += s[i];
        tmp += s[i+1];
        mp[tmp] += 1;
        c = max(mp[tmp], c);

    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if(c == it->second) {
            cout << it->first << endl;
            return (0);
        }
    }

    return (0);
}
