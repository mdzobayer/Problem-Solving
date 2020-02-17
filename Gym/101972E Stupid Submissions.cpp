#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, n, m, k, cnt, i, waNum, visiable;
    char caseLenght[10000+5], ch;
    cin >> test;
    while(test--) {
        cin >> n >> m >> k;
        cnt = 0;
        visiable = k;

        for (i = 1; i <= n; ++i) {
            cin >> ch;
            //cout << ch << endl;
            caseLenght[i] = ch;
        }

        for (i = 1; i <= m; ++i) {
            cin >> ch;
            if (ch != 'A') {
                cin >> waNum;
                if (visiable >= waNum) {
                    if (caseLenght[waNum] == 'S') {
                        ++cnt;
                    }
                }

                visiable = max(visiable, waNum);
            }
            else {
                visiable = n;
            }
        }

        cout << cnt << endl;
    }

    return (0);
}