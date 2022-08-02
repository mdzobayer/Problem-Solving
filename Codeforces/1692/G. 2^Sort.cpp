#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    int test, n, k, i;
    cin >> test;
    while(test--) {
        cin >> n >> k;



        int arr[n];
        bool marker[n];
        memset(marker, false, sizeof(marker));

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (i = 0; i < n-1; ++i) {
            marker[i] = (arr[i] < (2 * arr[i+1]));
        }
        // for (i = 0; i < n-1; ++i) {
        //     cout << marker[i] << " ";
        // }
        // cout << endl;

        int slideWindowTotal = 0, result = 0;
        for (i = 0; i < k; ++i) {
            slideWindowTotal += marker[i];
        }
        
        //cout << "slideWindowTotal = " << slideWindowTotal << endl;

        result += (slideWindowTotal == k);

        for (i = k; i < n; ++i) {
            slideWindowTotal += marker[i];
            //cout << "slideWindowTotal = " << slideWindowTotal << endl;
            slideWindowTotal -= marker[i - k];

            result += (slideWindowTotal == k);
        }

        cout << result << endl;
    }


    return (0);
}