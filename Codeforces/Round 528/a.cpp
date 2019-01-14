#include <bits/stdc++.h>


using namespace std;

int main() {

    string s, tmp="";
    cin >> s;

    if(s.size() == 1) {
        cout << s << endl;
    }
    else if(s.size() == 2) {
        cout << s << endl;
    }
    else if(s.size() == 3) {
        tmp += s[1];
        tmp += s[2];
        tmp += s[0];
        cout << tmp << endl;
    }
    else {
        int sz = s.size();
        int i = 0, j = sz - 1;
        tmp = "";
        if(sz % 2 == 0) {
            tmp += s[j];
            --j;
            while(i < j) {
                tmp += s[i];
                ++i;
                tmp += s[j];
                --j;
            }
            tmp += s[i];
        }
        else {
            tmp += s[i];
            ++i;
            while(i < j) {
                tmp += s[j];
                --j;
                tmp += s[i];
                ++i;
            }
            tmp += s[i];
        }

        //cout << tmp << endl;
        for (i = sz - 1; i >= 0; --i) {
            putchar(tmp[i]);
        }
        cout << endl;
    }


    return (0);
}
