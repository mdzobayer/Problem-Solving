#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileRead freopen("in.txt", "r", stdin);

using namespace std;

int main() {

    // fileRead

    int test, i, j, n, m, sum, index, arr[205][205], aggregateFrontSlashSum[410], aggregateBackSlashSum[410];
    cin >> test;
    while(test--) {

        memset(aggregateFrontSlashSum, 0, sizeof(aggregateFrontSlashSum));
        memset(aggregateBackSlashSum, 0, sizeof(aggregateBackSlashSum));

        cin >> n >> m;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                cin >> arr[i][j];

                index = i + j;
                aggregateFrontSlashSum[index] += arr[i][j];

                index = i - j;
                if (index < 0) {
                    index *= -1;
                    index += (n - 1);
                }
                aggregateBackSlashSum[index] += arr[i][j];
            }
        }

        int maxSum = INT_MIN;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                
                index = i + j;
                sum = aggregateFrontSlashSum[index];
                index = i - j;
                if (index < 0) {
                    index *= -1;
                    index += (n - 1);
                }
                sum += aggregateBackSlashSum[index];

                maxSum = max(maxSum, (sum-arr[i][j]));
            }
        }
        cout << maxSum << endl;
    }

    return (0);
}