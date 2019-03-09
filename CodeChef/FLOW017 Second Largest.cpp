#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, arr[3];
    cin >> test;
    while (test--) {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        if(arr[2] != arr[1]) {
            cout << arr[1] << endl;
        }
        else cout << arr[0] << endl;
    }

    return (0);
}
