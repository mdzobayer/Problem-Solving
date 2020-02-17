#include <bits/stdc++.h>

using namespace std;

#define ll long long int 
#define SIZE 200000+5
#define FASTIO ios_base::sync_with_stdio(false)

ll arr[SIZE], sum1[SIZE], sum2[SIZE];

int BinarySearch(ll sum[], int low, int high, ll key) {
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if (sum[mid] > key) {
            high = mid - 1;
        }
        else if (sum[mid] < key) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}


int main() {
    
   // FASTIO;

    ll i, n;
    int pos;
    sum1[0] = 0;

    cin >> n;

    for (i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum1[i] = arr[i] + sum1[i - 1];
    }

    sum2[n] = arr[n];
    for (i = n - 1; i > 0; --i) {
        sum2[i] = arr[i] + sum2[i + 1];
    }

    //cout << "Debug 1" << endl;

    for (i = 2; i <= n; ++i) {
        int pos = BinarySearch(sum1, 1, i - 1, sum2[i]);
        //cout << "Debug 2 pos " << pos << endl;
        if (pos > 0) {
            cout << sum2[i] << endl;
            return (0);
            break;
        }
    }
    cout << "0" << endl;

    return (0);
}