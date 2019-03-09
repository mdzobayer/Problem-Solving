#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, ocr, i, len;
    string s;
    cin >> test;
    cin.ignore();
    while(test--) {
        cin >> s;
        len = s.size();
        ocr = 0;
        for (i = 0; i < len; ++i) {
            if(s[i] == '4')
                ++ocr;
        }
        cout << ocr << endl;
    }

    return (0);
}
