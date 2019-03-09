#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int test, i, n, ans;
    cin >> test;
    while(test--) {
        cin >> n;
        ans = 0;
        //while(n > 0) {
            for (i = 11; i >= 0; --i) {
                if (arr[i] <= n) {
                    ans += (n / arr[i]);
                    n = n % arr[i];
                }
            }
       // }
        cout << ans << endl;
    }

    return (0);
}
