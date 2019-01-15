#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, i, extrema = 0, arr[1000+5];
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (i = 1; i < n - 1; ++i) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            ++extrema;
        else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
            ++extrema;
    }
    cout << extrema << endl;

    return (0);
}
