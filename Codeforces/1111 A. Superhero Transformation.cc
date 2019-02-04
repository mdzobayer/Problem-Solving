#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}


int main() {

    string s, t;
    int n1, n2;
    int i;
    bool ans;
    cin >> s >> t;
    n1 = s.size();
    n2 = t.size();

    if(n1 != n2) {
        cout << "No" << endl;
        return (0);
    }

    int r = min(n1, n2);

    for (i = 0; i < r; ++i) {
        if(isVowel(s[i]) != isVowel(t[i])) {
            cout << "No" << endl;
            return (0);
        }
    }
    cout << "Yes" << endl;

    return (0);
}
