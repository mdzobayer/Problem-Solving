#include <bits/stdc++.h>


using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int i, n, m, j;
    map <string, string > sta, host;
    string s1, s2, temp;
    cin >> n >> m;

    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> s1 >> s2;
        sta[s2] = s1;
    }
    for (i = 0; i < m; ++i) {
        //cin.ignore();
        temp = "";
        cin >> s1 >> s2;
        for (j = 0; s2[j] != ';'; ++j) {
            temp += s2[j];
        }
        cout << s1 << " " << s2 << " #" << sta[temp] << endl;
    }

    return (0);

    }
