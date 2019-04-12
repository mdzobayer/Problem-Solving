#include <bits/stdc++.h>

using namespace std;


int main() {

    freopen("in.txt", "r", stdin);

    int test,i, len;
    string s1, s2, s3;

    cin >> test;
    cin.ignore();
    while(test--) {
        cin >> s1 >> s2;
        len = s1.size();
        for (i = 0; i < len; ++i) {
            s1[i] = tolower(s1[i]);
        }

        len = s2.size();
        for (i = 0; i < len; ++i) {
            s2[i] = tolower(s2[i]);
        }
        s3 = "";
        s3 = s1;
        for (i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'p')
                s1[i] = 'b';
            else if (s1[i] == 'e')
                s1[i] = 'i';
        }
        
        if (s1 == s2 || s1 == s3) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

    }

    return (0);
}