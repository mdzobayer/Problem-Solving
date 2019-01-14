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
int arr[10000];

int main() {
    FastRead

    //fRead("in.txt");

    int n, i, j;
    while ( cin >> n) {
        if (n == 0) break;
        while(1) {
            cin >> arr[0];
            if (arr[0] == 0){
                printf("\n");
                break;
            }
            for (i = 1; i < n; ++i) {
                cin >> arr[i];
            }
            stack<int> station;
            i = 1;
            j = 0;

            while( i <= n) {
                station.push(i);
                while(!station.empty() && station.top() == arr[j]) {
                    station.pop();
                    ++j;
                    if (j >= n) break;
                }
                ++i;
                if (i > n) break;
            }
            if (station.empty()) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }

    return (0);
}
