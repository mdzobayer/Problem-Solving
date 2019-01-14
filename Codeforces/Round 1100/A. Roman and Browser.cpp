#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int arr[105];
bool close[105];

int main() {

    int n, i, k, e , s, j, sc, maximal, x;

    cin >> n >> k;

    for (i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    maximal = 0;
    for (i = 1; i <= n; ++i) {
        memset(close, false, sizeof(close));

        //cout << n << " " << i << endl;
        for (j = i; j <= n; j += k) {
            close[j] = true;
            //cout << "Debug 1" << endl;
        }
        for (j = i; j > 0; j -= k) {
            close[j] = true;
            //cout << "Debug 2 " << j << endl;
            //Sleep(1000);
        }
        e = s = 0;
        for (x = 1; x <= n; ++x) {
            if(close[x] == false) {
                if(arr[x] == 1)
                    ++e;
                else ++s;
            }
        }
        e = abs(e - s);
        maximal = max(maximal, e);
    }

    cout << maximal << endl;

    return (0);
}
