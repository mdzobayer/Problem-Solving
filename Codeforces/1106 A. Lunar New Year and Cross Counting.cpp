#include <bits/stdc++.h>

using namespace std;

int n;

bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }
    return true;
}

int main() {

    //freopen("in.txt", "r", stdin);


    int i, j, cn = 0;
    string s[505];
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (i = 1; i < n - 1; ++i) {
        for (j = 1; j < n - 1; ++j) {
            if(s[i][j] == 'X') {
                if(s[i - 1][j - 1] != 'X')
                    continue;
                if(s[i - 1][j + 1] != 'X')
                    continue;
                if(s[i + 1][j - 1] != 'X')
                    continue;
                if(s[i + 1][j + 1] != 'X')
                    continue;
                ++cn;
            }
        }
    }
    cout << cn << endl;


    return (0);
}
