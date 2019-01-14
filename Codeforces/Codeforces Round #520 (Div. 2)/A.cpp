#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, i, c, mx, arr[100+5];
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    mx = 0, c = 1;
    bool track;
    if(arr[0] == 1) track = true;
    else track = false;

    for (i = 1; i < n; ++i) {
        if(arr[i - 1] + 1 == arr[i]) {
            //cout << "c is " << c << endl;
            //cout << "c is " << c << endl;
            ++c;

        }
        else {
            if(track) {
                track = false;
                mx = max(c - 1, mx);
                c  = 1;
            }
            else {
                mx = max (c - 2, mx);
                //cout << "Debug" << endl;
                c = 1;
            }
        }
    }
    if(arr[n - 1] == 1000 && track) {
        mx = max(c - 2, mx);
    }
    else if(arr[n - 1] == 1000 || track)
        mx = max(c - 1, mx);
    else {
        //cout << "Debug 2" << endl;
        mx = max(c - 2, mx);
    }

    cout << mx << endl;

    return (0);
}
