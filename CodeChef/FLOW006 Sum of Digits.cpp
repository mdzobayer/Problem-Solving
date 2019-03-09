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
        for (i = 0; i < s.size(); ++i) {
            sum += s[i] - '0';
        }
        cout << sum << endl;
    }

    return (0);
}
