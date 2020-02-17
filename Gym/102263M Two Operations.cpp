#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, current = "", opr;
    int i, len;
    bool resize = true;

    cin >> s;
    sort(s.begin(), s.end());

    reverse(s.begin(), s.end());

    //cout << s << endl;
    len = s.size();
    
    while(true) {

        len = s.size();
        current = "";
        resize = false;

        for (i = 0; i < len; ++i) {
            opr = " ";
            if (len - i == 1) {
                opr[0] = s[i];
                current += opr;
            }
            else if (s[i] == s[i + 1] && s[i] < 'z') {
                opr[0] = s[i] + 1;
                current += opr;
                ++i;
                resize = true;
            }
            else {
                opr[0] = s[i];
                current += opr;
            }
        }
        //cout << "Current: " << current << endl;
        s = current;

        if (resize == false) break;
    }

    cout << s << endl;

    return (0);
}