
#include <bits/stdc++.h>


using namespace std;

string easy(string s) {

    string tmp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            tmp += s[i] + 32;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            tmp += s[i] + 32;
        }
    }
    return tmp;
}

int main() {

    string pre[10], s, a, b, c;
    int n, j, i;
    cin >> a >> b >> c;
    a = easy(a);
    b = easy(b);
    c = easy(c);
    pre[0] = a + b + c;
    pre[1] = a + c + b;
    pre[2] = b + a + c;
    pre[3] = b + c + a;
    pre[4] = c + b + a;
    pre[5] = c + a + b;
    pre[6] = a + b + c;
    pre[7] = a + b + c;

    cin >> n;
    bool check;
    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> s;
        s = easy(s);
        check = false;
        for (j = 0; j < 6; ++j) {
            if (pre[j] == s) {
                check = true;
            }
        }
        if (check) {
            printf("ACC\n");
        }
        else printf("NO\n");
    }

    return (0);
}
