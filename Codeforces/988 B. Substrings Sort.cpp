#include <bits/stdc++.h>

using namespace std;

int main() {

    vector < pair < int, string> > vt;
    int n, i, x;
    string s, s1;
    cin >> n;
    cin.ignore();

    for (i = 0; i < n; ++i) {
        cin >> s;
        x = s.size();
        vt.push_back(make_pair(x, s));
    }
    sort(vt.begin(), vt.end());

    for (i = 1; i < n; ++i) {
        s1 = vt[i - 1].second;
        s = vt[i].second;
        size_t found = s.find(s1);
        if(found == string::npos) {
            cout << "NO" << endl;
            return (0);
        }
    }
    cout << "YES" << endl;
    for (i = 0; i < n; ++i) {
        cout << vt[i].second << endl;
    }

    return (0);
}
