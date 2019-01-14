#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("in.txt", "r", stdin);
    int i = 1, zeros = 1;
    string s;
    while (getline(cin, s)) {
            //cout << s << endl;
        if (s == "0") ++zeros;
        if (zeros == 67 || zeros == 123)
            cout << "line is " << i << endl;
        if (zeros > 125) break;
        ++i;
    }

    return (0);
}
