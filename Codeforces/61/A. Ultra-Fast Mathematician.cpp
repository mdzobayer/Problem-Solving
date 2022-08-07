#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {

    fastIO;

    string s1, s2;
    int i, x;

    cin >> s1 >> s2;
    for (i = 0; i < s1.size(); ++i) {
        x = (s1[i] - '0') ^ (s2[i] - '0');
        cout << x;
    }
    cout << endl;

    return (0);
}