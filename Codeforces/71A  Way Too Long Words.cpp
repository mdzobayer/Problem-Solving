
#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, len;
    string s;
    cin >> test;
    cin.ignore();

    while(test--) {
        cin >> s;
        len = s.size();
        if(len < 11) {
            cout << s << endl;
        }
        else {
            cout << s[0] << len-2 << s[len-1] << endl;
        }
    }

    return (0);
}
