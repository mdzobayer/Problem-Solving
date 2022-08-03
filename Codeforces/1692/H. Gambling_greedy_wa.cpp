#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("in.txt", "r", stdin);

    int test, n, i;

    cin >> test;
    while(test--) {
        cin >> n;

        long long int profitValue;
        int arr[n], maximumCount, maximumValue;
        map<int, int> maximumCounts;

        for (i = 0; i < n; ++i) {
            cin >> arr[i];

            maximumCounts[arr[i]] = 1;
        }

        int consecutiveCount = 1;
        for (i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                ++consecutiveCount;
            } else {

                maximumCounts[arr[i-1]] = max(maximumCounts[arr[i-1]], consecutiveCount);
                consecutiveCount = 1;
            }
        }

        if (consecutiveCount > 1) {
            maximumCounts[arr[n-1]] = max(maximumCounts[arr[n-1]], consecutiveCount);
        }

        map<int, int>::iterator it = maximumCounts.begin();
        maximumValue = it->first;
        maximumCount = it->second;

        for ( ; it != maximumCounts.end(); ++it) {
            if (it->second > maximumCount) {
                maximumValue = it->first;
                maximumCount = it->second;
            }
        }

        profitValue = 1;
        int finalL = 0, finalR = 0, currentL = 0;

        long long int currentProfit = 1;
        for (i = 0; i < n; ++i) {
            if (arr[i] == maximumValue) {
                currentProfit <<= 1;
            } else {
                currentProfit >>= 1;
            }

            if (currentProfit > profitValue) {
                profitValue = currentProfit;
                finalL = currentL;
                finalR = i;

            } else if (currentProfit < 1) {
                currentProfit = 1;
                currentL = i + 1;
            }

            //cout << "i = " << i + 1 << " currentProfit " << currentProfit << " profitValue = " << profitValue << endl;
        }

        cout << maximumValue << " " << finalL + 1 << " " << finalR + 1 << endl;

    }

    return (0);
}