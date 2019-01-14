#include <iostream>
#include <cstdio>
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

void digitSum(int sum[], int x, int base) {
    while(x != 0) {
        sum[base] += (x % base);
        x /= base;
    }
}

int main() {
    //FastRead

    int sum[18], i;
    for (i = 2992; i <= 10000; ++i) {
        sum[10] = sum[12] = sum[16] = 0;
        digitSum(sum, i, 10);
        digitSum(sum, i, 12);
        digitSum(sum, i, 16);
        if (sum[10] == sum[12] && sum[12] == sum[16]){
            printf("%d\n", i);
        }
    }


    return (0);
}
