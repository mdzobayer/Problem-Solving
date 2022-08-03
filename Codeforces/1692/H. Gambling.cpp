#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    int test, n, i;

    cin >> test;
    while(test--) {
        cin >> n;

        int x, positionDistance, maximumValue = 0, maximumCount = 0, finalL, finalR;

        map<int, int> numberOfCounts;
        map<int, int> mostRecentPosition;
        map<int, int> possibleL;

        for (i = 0; i < n; ++i) {
            cin >> x;
            if (numberOfCounts.find(x) == numberOfCounts.end()) {
                numberOfCounts[x] = 1;
                possibleL[x] = i;
            } else {
                numberOfCounts[x] += 1;
                positionDistance = (i - mostRecentPosition[x] - 1);
                numberOfCounts[x] -= positionDistance;
                if (numberOfCounts[x] < 1) {
                    numberOfCounts[x] = 1;
                    possibleL[x] = i;
                }
            }
            mostRecentPosition[x] = i;

            if (maximumCount < numberOfCounts[x]) {
                maximumValue = x;
                maximumCount = numberOfCounts[x];
                finalL = possibleL[x];
                finalR = i;
            }

        }

        cout << maximumValue << " " << finalL + 1 << " " << finalR + 1 << endl;

    }

    return (0);
}