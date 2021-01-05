#include <bits/stdc++.h>

using namespace std;

int helper[10000+5];

int main() {

    string s, s1;

    int len, i, sum, j;


    helper[1] = 1;
    for (i = 2; i < 10000+5; ++i) {
        helper[i] = (helper[i-1] * 2) % 131071;
    }

    while(cin >> s1) {
        
        s = s1;

        len = s1.size();
        i = len - 1;

        while(s1[i] != '#') {
            cin >> s1;
            s += s1;

            len = s1.size();
            i = len - 1;
        }

        i = s.size() - 2;
        sum = 0;
        j = 1;
        while(i >= 0) {
            if (s[i] == '1') {
                sum += helper[j];
                sum %= 131071;
            }

            ++j;
            --i;
        }

        if (sum == 0) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }


    return (0);
}