#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, i, sum;
    string s;
    cin >> test;
    cin.ignore();
    while(test--) {
        sum = 0;
        s = "";
        cin >> s;

        int len = s.size();
        sum = s[0] - '0';
        sum += s[len-1] - '0';

        cout << sum << endl;
    }

    return (0);
}

