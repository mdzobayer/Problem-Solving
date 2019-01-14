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

int key[30];


int main() {
    FastRead

    key[0] = 2;
    key[1] = 2;
    key[2] = 2;

    key[3] = 3;
    key[4] = 3;
    key[5] = 3;

    key[6] = 4;
    key[7] = 4;
    key[8] = 4;

    key[9] = 5;
    key[10] = 5;
    key[11] = 5;

    key[12] = 6;
    key[13] = 6;
    key[14] = 6;

    key[15] = 7;
    key[16] = 7;
    key[17] = 7;
    key[18] = 7;

    key[19] = 8;
    key[20] = 8;
    key[21] = 8;

    key[22] = 9;
    key[23] = 9;
    key[24] = 9;
    key[25] = 9;

    int i;
    char str[35];
    while(scanf("%s", &str) == 1) {
        for (i = 0; str[i]; ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                putchar(key[str[i] - 'A'] + '0');
            }
            else {
                putchar(str[i]);
            }
        }
        putchar('\n');
    }

    return (0);
}
