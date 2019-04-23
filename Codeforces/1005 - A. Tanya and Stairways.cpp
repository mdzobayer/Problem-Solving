#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, arr[1000+5], i, cn = 1;

    vector < int > vt;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            ++cn;
        }
        else {
            vt.push_back(cn);
            cn = 1;
        }
    }
    vt.push_back(cn);
    cout << vt.size() << endl;
    for (i = 0; i < vt.size(); ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;

    return (0);
}