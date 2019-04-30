#include <bits/stdc++.h>

using namespace std;

int n, i, j;
string s[50];

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return false;

    if (s[x][y] == '.') return true;

    return false;
}

void Mark(int x, int y) {
    s[x][y] = '#';
    s[x - 1][y] = '#';
    s[x + 1][y] = '#';
    s[x][y + 1] = '#';
    s[x][y - 1] = '#';
}


int main() {

    cin >> n;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                if (isValid(i - 1, j)) {
                    if (isValid(i, j - 1)) {
                        if (isValid(i, j + 1)) {
                            if (isValid(i + 1 , j)) {
                                Mark(i, j);
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                cout << "NO" << endl;
                return (0);
            }
        }
    }

    cout << "YES" << endl;

    return (0);
}