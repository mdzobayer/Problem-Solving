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

int arr[10000 + 5];

int main() {
    FastRead
    //fRead("in.txt");
    //fWrite("out.txt");
    memset(arr, 0, sizeof(arr));
    int x, y, z, i, maxLength = 0;
    while(scanf("%d %d %d", &x, &y, &z) == 3) {
        if (z > maxLength) {
            maxLength = z;
        }
        for (i = x; i < z; ++i) {
            if (arr[i] < y) {
                arr[i] = y;
            }
        }
    }

    for (i = 1; i <= maxLength; ++i) {
        if (arr[i] > arr[i - 1]) {
            if (i != 1) printf(" ");
            printf("%d %d", i, arr[i]);
        }
        else if (arr[i] < arr[i - 1]) {
            if (i != 1) printf(" ");
            printf("%d %d", i, arr[i]);
        }
    }
    printf("\n");

    return (0);
}
