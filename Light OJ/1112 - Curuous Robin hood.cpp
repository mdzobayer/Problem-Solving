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

//int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
//                  {0,-1,1,0,-1,1,1,-1}};

//int knight[2][8] = {{-2,-2,-1,1,2,2,1,-1},
//                    {-1,1,2,2,1,-1,-2,-2}};

/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

LLI arr[100000+5], preSum[100000+10];

LLI getSum(LLI c) {
    LLI sum = 0;

    while(c > 0) {
        sum += preSum[c];
        c -= c & (-c);
    }
    return sum;
}
void updateSum(LLI c, LLI value, LLI n) {
    c += 1;
    while(c <= n) {
        preSum[c] += value;
        c += c & (-c);
    }
}

int main() {

    //fRead("in.txt");
    //fWrite("out.txt");

    LLI test, t, n, q, i, cmd, ind, value;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        printf("Case %lld:\n", t);
        scanf("%lld %lld", &n, &q);

        for (i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            preSum[i] = 0;
        }
        preSum[i] = 0;
        preSum[i+1] = 0;
        for (i = 0; i < n; ++i) {
            updateSum(i, arr[i], n);
        }
        for (i = 0; i < q; ++i) {
            scanf("%lld", &cmd);
            if (cmd == 1) {
                scanf("%lld", &ind);
                /// set -arr[i];
                printf("%lld\n", arr[ind]);
                updateSum(ind, (-arr[ind]), n);
                arr[ind] = 0;
            }
            else if (cmd == 2) {
                scanf("%lld %lld", &ind, &value);
                /// Update
                arr[ind] += value;
                updateSum(ind, value, n);
            }
            else {
                scanf("%lld %lld", &value, &ind);
                if (value > ind) {
                    swap(ind, value);
                }
                /// Sum
                printf("%lld\n", getSum(ind+1) - getSum(value));
            }
        }
    }

    return (0);
}
