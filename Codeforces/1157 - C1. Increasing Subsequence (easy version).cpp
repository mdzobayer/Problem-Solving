#include <bits/stdc++.h>

using namespace std;

int n, arr[200000+10], i;

int main() {

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int l, r, ans = 0;

    l = 0;
    r = n - 1;

    int c = 0;
    string s = "";

    while(l <= r) {
        if (arr[l] > c && arr[r] > c) {
            if (arr[l] < arr[r]) {
                s += 'L';
                c = arr[l];
                ++l;
            }
            else {
                s += 'R';
                c = arr[r];
                --r;
            }
        }
        else if (arr[l] > c) {
            s += 'L';
            c = arr[l];
            ++l;
        }
        else if (arr[r] > c) {
            s += 'R';
            c = arr[r];
            --r;
        }
        else break;
    }
    cout << s.size() << endl;
    cout << s << endl;

    return (0);
}