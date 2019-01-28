#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, i, j, Count = 0;

    string s, s1 = "RGB";
    cin >> n >> s;

    for (i = 0; i < n - 1; ) {
        if(s[i] == s[i + 1]) {
            for (j = 0; j < 3; ++j) {
                if(s[i] != s1[j] && s[i+2] != s1[j]) {
                    ++Count;
                    s[i + 1] = s1[j];
                    break;
                }
            }
            i += 2;
        }
        else ++i;
    }
    cout << Count << endl << s << endl;

    return (0);
}
