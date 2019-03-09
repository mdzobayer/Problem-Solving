#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, i, sum, zero;
    string s;
    cin >> test;
    cin.ignore();
    while(test--) {
        sum = 0;
        s = "";
        cin >> s;

        reverse(s.begin(), s.end());
        zero = 0;
        while(s[zero] == '0') ++zero;

        s = s.substr(zero);

        cout << s << endl;
    }

    return (0);
}


