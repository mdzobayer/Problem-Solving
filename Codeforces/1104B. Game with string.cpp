

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i, j, n;
    bool turn = true;
    n = s.size();
    --n;
    i = 0; j = 1;
    label:

    for ( ; i < n; ++i) {
        while(s[i] == ' ') {
            ++i;
        }
        j = i + 1;
        while(s[j] == ' ') {
            ++j;
        }

        if(s[i] == s[j]) {
            s[i] = ' ';
            s[j] = ' ';
            if(turn) turn = false;
            else turn = true;
            i = j;
        }
    }


    for ( i = 0, j = 1 ; i < n; ++i) {
        while(s[i] == ' ') {
            ++i;
        }
        j = i + 1;
        while(s[j] == ' ') {
            ++j;
        }

        if(s[i] == s[j]) {
            s[i] = ' ';
            s[j] = ' ';
            if(turn) turn = false;
            else turn = true;
            i = j;
            goto label;
        }
    }

    if(turn) cout << "No" << endl;
    else cout << "Yes" << endl;

    return (0);
}
