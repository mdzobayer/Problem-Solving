#include <bits/stdc++.h>

using namespace std;
map < string, int > lib;
map < string, int >::iterator it;

int main() {

    //freopen("in.txt", "r", stdin);

    int n, i, len;
    string s, tmp;

    while(cin >> len >> s) {

        lib.clear();

        n = s.size() - len;

        for (i = 0; i <= n; ++i) {
            tmp = s.substr(i, len);
            if (lib.find(tmp) != lib.end()) {
                lib[tmp] += 1;
            }
            else {
                lib[tmp] = 1;
            }
        }
        it = lib.begin();
        tmp = it->first;
        len = it->second;
        for (it; it != lib.end(); ++it) {
            if (len < it->second) {
                len = it->second;
                tmp = it->first;
            }
        }
        cout << tmp << endl;
    }

    return (0);
}
