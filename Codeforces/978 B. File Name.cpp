#include <bits/stdc++.h>

using namespace std;



int main() {

    int n, i, cn = 0, toRm = 0;
    string s;
    cin >> n >> s;
    for (i = 0; i < n; ++i) {
        if(s[i] == 'x') {
            ++cn;
        }
        else {
            cn = 0;
        }

        if(cn == 3) {
            toRm++;\
            --cn;
        }
    }
    cout << toRm << endl;

    return (0);
}
