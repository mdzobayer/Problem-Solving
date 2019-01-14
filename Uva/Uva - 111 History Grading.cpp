#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================


int lcs(const int *arr1, const int *arr2, const int & n) {

    int table[n + 1][n + 1], i, j;

    for (i = 0; i <= n; ++i) {
        for (j = 0; j <= n; ++j) {
            if(i == 0 || j == 0) {
                table[i][j] = 0;
            }
            else if (arr1[i - 1] == arr2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[n][n];
}

int main() {
    FastRead

    fRead("in.txt");

    int n, i, x, arr1[25], arr2[25];
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i : arr1) {
        printf("%d ", i);
    }
    printf("\n");

    while(true) {
        if (cin >> x) {
            arr2[0] = x;
            for (i = 1; i < n; ++i) {
                cin >> arr2[i];
            }

            for (int i : arr2) {
                printf("%d ", i);
            }
            printf("\n");
            cout << lcs(arr1, arr2, n) << endl;

        }
        else return (0);
    }


    return (0);
}
