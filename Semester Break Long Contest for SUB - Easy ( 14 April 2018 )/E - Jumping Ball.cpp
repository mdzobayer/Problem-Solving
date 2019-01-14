#include <bits/stdc++.h>


using namespace std;


int main() {

    int n,i, oAngle = 0, cAngle = 0;
    string s;
    cin >> n;
    cin.ignore();
    cin >> s;
    for (i = 0; i < n; ++i) {
        if (s[i] == '<')
            ++oAngle;
        else break;
    }
    for (i = n - 1; i >= 0; --i) {
        if (s[i] == '>')
            ++cAngle;
        else break;
    }
    cout << oAngle + cAngle << endl;

    return (0);
}
