#include <bits/stdc++.h>


using namespace std;
int n, k;
string str[100];
bool cRight(int i, int j) {
    int cnn = 1;
    for ( ++j; j < n; ++j) {
        if (str[i][j] == '.') {
            ++cnn;
        }
        else break;
    }
    if (cnn >= k) return true;
}
bool cDown(int i, int j) {
    int cnn = 1;
    for ( ++i; i < n; ++i) {
        if (str[i][j] == '.') {
            ++cnn;
        }
        else break;
    }
    if (cnn >= k) return true;
}
int main() {

    int i, j;
    cin >> n >> k;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        getline(cin, str);
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (str[i][j] == '.') {
                if (cRight(i,j) || cDown(i,j)){
                    cout << i + 1 << " " << j + 1 << endl;
                }
                return (0);
            }
        }
    }
    cout << 1 << " " << 1 << endl;
    return (0);
}
