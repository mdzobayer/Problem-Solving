#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, n, H, M, i, hi, mi, ansH, ansM, timeInMinutes;
    cin >> test;
    while(test--) {
        cin >> n >> H  >> M;

        vector<int> alarmTimes;

        for (i = 0; i < n; ++i) {
            cin >> hi >> mi;
            alarmTimes.push_back((hi * 60) + mi);
        }
        sort(alarmTimes.begin(), alarmTimes.end());

        bool ansFound = false;

        int sleepTime = ((H * 60) + M);

        for (i = 0; i < n; ++i) {
            if (alarmTimes[i] >= sleepTime) {

                timeInMinutes = alarmTimes[i] - sleepTime;

                ansH = (timeInMinutes / 60);
                ansM = (timeInMinutes % 60);

                ansFound = true;
                break;
            }
        }

        if (!ansFound) {
            timeInMinutes = (24 * 60) - sleepTime;
            timeInMinutes += alarmTimes[0];

            ansH = timeInMinutes / 60;
            ansM = timeInMinutes % 60;

        }
        cout << ansH << " " << ansM << endl;

    }

    return (0);
}