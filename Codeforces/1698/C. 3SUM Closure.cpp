#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n, i, j, k, l, x, negativeCount, positiveCount, zeroCount;
    vector<int> numbers;
    bool foundAns;

    cin >> n;

    negativeCount = positiveCount = zeroCount = 0;

    for (i = 0; i < n; ++i) {
        cin >> x;

        if (x == 0 && zeroCount < 3) {
            numbers.push_back(x);
            ++zeroCount;
        } else if(x < 0) {
            ++negativeCount;
            numbers.push_back(x);
        } else if(x > 0) {
            ++positiveCount;
            numbers.push_back(x);
        }
    }

    if (positiveCount > 2 || negativeCount > 2) {
        cout << "NO" << endl;
        return;
    }

    n = numbers.size();

    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            for (k = j + 1; k < n; ++k) {
                foundAns = false;
                for (l = 0; l < n; ++l) {
                    if ((numbers[i] + numbers[j] + numbers[k]) == numbers[l]) {
                        // cout << "sum = " << (numbers[i] + numbers[j] + numbers[k]) << " " << numbers[l] << endl;
                        foundAns = true;
                        break;
                    }

                }

                if (!foundAns) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {  

    // freopen("in.txt", "r", stdin);  

    int test;

    cin >> test;
    while(test--) {
        solve();
    }

    return (0);
}