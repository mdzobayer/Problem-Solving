#include <bits/stdc++.h>


using namespace std;

bool isvowel(const char & ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i'
        || ch == 'o' || ch == 'u')
            return true;
    return false;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int n, i;
    bool flag;
    string s1, s2;
    while(cin >> n) {
        cin.ignore();
        while(n--) {
            cin >> s1;
            cin.ignore();
            cin >> s2;
            cin.ignore();
            flag = true;
            if (s1.size() != s2.size()) {
                cout << "No" << endl;
                flag = false;
            }
            else {
                for (i = 0; i < s1.size(); ++i) {
                    if (s1[i] != s2[i]) {
                        if (isvowel(s1[i]) && isvowel(s2[i])) {

                        }
                        else {
                            cout << "No" << endl;
                            flag = false;
                            i = s1.size()+1;
                        }
                    }
                }
            }
            if (flag) {
                cout << "Yes" << endl;
            }
        }
    }

    return (0);
}
