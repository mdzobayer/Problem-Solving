#include <bits/stdc++.h>

using namespace std;

#define MAX 4005

struct subStr {
    int tupl[2], index;

    bool operator < (const subStr &tmp) const {
        if(this->tupl[0] != tmp.tupl[0]) {
            return this->tupl[0] < tmp.tupl[0];
        }
        return this->tupl[1] < tmp.tupl[1];
    }
};

int main() {
    //cout << "Debug -1" << endl;

    subStr arr[MAX];
    int Rank[18][MAX], step, i, j, n, jump;
    string text = "CCCCC";
    n = text.size();
    //cout << "Debug 0" << endl;

    // Rank suffixes according to 1st character
    for (j = 0; j < n; ++j) {
        Rank[0][j] = text[j];
        memset(arr[j].tupl, 0, sizeof(arr[j].tupl));
    }
    //cout << "Debug 1" << endl;
    for (step = 1, jump = 1; jump < n; ++step, jump <<= 1) {
        for (j = 0; j <= n; ++j) {
            arr[j].index = j;
            arr[j].tupl[0] = Rank[step - 1][j];
            arr[j].tupl[1] = j + jump < n ? Rank[step - 1][j + jump] : -1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].index] = 0;
        for (j = 1; j < n; ++j) {
            if((arr[j].tupl[0] == arr[j-1].tupl[0]) && (arr[j].tupl[1] == arr[j-1].tupl[1]))
                Rank[step][arr[j].index] = Rank[step][arr[j-1].index];
            else Rank[step][arr[j].index] = j;
        }
    }
    cout << "Suffix Array:" << endl;
    for (i = 0; i < n; ++i) {
        cout << arr[i].index << ' ' << text.substr(arr[i].index) << endl;
    }

    return (0);
}
