#include <bits/stdc++.h>

using namespace std;

bool duplic[1000+5];
int n, arr[55];

int main() {
    int i;

    memset(duplic, false, sizeof(duplic));

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        duplic[arr[i]] = true;
    }
    vector < int > vt;
    for (i = n - 1; i >= 0; --i) {
        if(duplic[arr[i]]) {
            vt.push_back(arr[i]);
            duplic[arr[i]] = false;
        }
    }
    cout << vt.size() << endl;

    for (i = vt.size() - 1; i >= 0; --i) {
        cout << vt[i] << " ";
    }
    cout << endl;



    return (0);
}
