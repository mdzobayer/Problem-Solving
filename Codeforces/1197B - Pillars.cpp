#include <bits/stdc++.h>

using namespace std;

int arr[200000+5];

int main() {

    int n, i, mx = 0, mxIndx = 0, left, right;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] > mx) {
            mx = arr[i];
            mxIndx = i;
        }
    }

    left = mxIndx - 1;
    right = mxIndx + 1;

    while(left >= 0 || right < n) {

        if (arr[left] < mx && arr[right] < mx) {
            if (arr[left] > arr[right]) {
                mx = arr[left];
                --left;
            }
            else {
                mx = arr[right];
                ++right;
            }
        }
        else { 
            break;
        }
    }

    if (left < 0 && right >= n) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;




    return (0);
}