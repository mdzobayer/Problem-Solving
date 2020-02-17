#include <bits/stdc++.h>

#define SIZE 100000+5
using namespace std;

int arr[SIZE], n, record[35][SIZE];

int getValue(int base, int indx) {
    
}

void recordProcess() {
    
    for (i = 1; i <= 32; i *= 2) {
        for (j = 1; j <= n; ++j) {
            record[j][i] = min(record[j][i/2], record[j + (i/2) + 1][i/2]);
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);
    int test, t, i, q, qs, qe;

    scanf("%d", &test);
    for ( t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &q);

        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        
        printf("Case %d:\n", t);
        for (i = 0; i < q; ++i) {
            scanf("%d %d", &qs, &qe);

        }

    }

    return (0);
}
