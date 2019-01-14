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

int main() {
    FastRead

    ULL a, b, t = 0, sum1, remainder, sum2, len, i, digit, multi;

    while(cin >> a >> b) {
        if (a == 0 && b == 0) break;
        ++b;
        if (a == 0) sum1 = 0;
        else {
            len = floor(log2(a) + 1);
            sum1 = 0;
            digit = 2;
            multi = 1;
            for (i = 0; i < len; ++i) {
                sum1 += (a / digit) * multi;

                remainder = a % digit;
                if (remainder > multi) {
                    sum1 += (remainder - multi);
                }

                digit += digit;
                multi += multi;
            }
        }

        len = floor(log2(b) + 1);
        sum2 = 0;
        digit = 2;
        multi = 1;
        for (i = 0; i < len; ++i) {
            sum2 += (b / digit) * multi;

            remainder = b % digit;
            if (remainder > multi) {
                sum2 += (remainder - multi);
            }

            digit += digit;
            multi += multi;
        }
        cout << "Case " << ++t << ": "
             << sum2 - sum1 << endl;
    }


    return (0);
}
