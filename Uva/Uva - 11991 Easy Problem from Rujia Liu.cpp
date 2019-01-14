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


LLI ocarance[1000000+2][3];
LLI arr[1000000+2];

int main() {
    FastRead

    //fRead("in.txt");

    LLI i, n, m, num, k, ocCount, j;

    while(cin >> n >> m) {

        memset(ocarance, -1, sizeof(ocarance));

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
            if (ocarance[arr[i]][0] == -1) {
                ocarance[arr[i]][0] = i;
                ocarance[arr[i]][1] = i;
                ocarance[arr[i]][2] = 1;
            }
            else {
                ocarance[arr[i]][1] = i;
                ocarance[arr[i]][2] += 1;
            }
        }
        for (i = 0; i < m; ++i) {
            cin >> k >> num;
            if (ocarance[num][2] < k) {
                cout << 0 << endl;
            }
            else {
                ocCount = 0;
                for (j = ocarance[num][0]; j <= ocarance[num][1]; ++j) {
                    if (arr[j] == num){
                        ++ocCount;
                    }
                    if (ocCount == k) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
    }


    return (0);
}
