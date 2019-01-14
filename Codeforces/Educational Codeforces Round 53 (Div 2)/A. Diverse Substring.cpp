#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, arr[130];
    memset(arr, 0 , sizeof(arr));
    string s;
    cin >> n;
    cin.ignore();
    cin >> s;

    for (i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            printf("YES\n%c%c\n", s[i-1], s[i]);
            return (0);
        }
    }
    printf("NO\n");
    return (0);
    /*
    for (i = 0; i < n; ++i) {
        ++arr[s[i]];
    }
    int half = n / 2;

    for (i = 0; i < n - 1; ++i) {
        tmp = "";
        for (j = i + 1; j < n; ++j) {
            tmp = s.substr(i, j);
            memset(arr, 0, sizeof(arr));
            for (k = 0; k < tmp.size(); ++k) {
                arr[tmp[k]]++;
            }
            for (k = 'A'; k <= 'z'; ++k) {
                arr[]
            }
        }
    }
*/
    return (0);
}
