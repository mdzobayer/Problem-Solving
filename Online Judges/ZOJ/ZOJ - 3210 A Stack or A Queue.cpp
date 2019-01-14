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
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================
int arr[100+10];
int main() {
    //FastRead

    //fRead("in.txt");

    int n, i, j, test, temp;
    bool isStack, isQueue;
    cin >> test;
    while(test--) {
        cin >> n;

        isStack = isQueue = true;

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
            cin >> temp;
            if (arr[i] != temp) {
                isQueue = false;
            }
            if (arr[j] != temp) {
                isStack = false;
            }
        }
        if (isStack && isQueue) {
            printf("both\n");
        }
        else if (!isStack && !isQueue) {
            printf("neither\n");
        }
        else if (isStack) {
            printf("stack\n");
        }
        else {
            printf("queue\n");
        }
    }

    return (0);
}
