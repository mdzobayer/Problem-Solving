#include <bits/stdc++.h>


using namespace std;
int arr[200000+5], vis[200000+5];

int main() {

    int i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        vis[arr[i]] = i;
    }
    int last = n;
    for (i = 200000; i > 0; --i) {
        if(vis[i] > 0) {
            last = min(last, vis[i]);
        }
    }
    for (i = 1; i < n; ++i) {
        if(last == vis[i]) {
            cout << i << endl;
            break;
        }
    }

    return (0);
}
