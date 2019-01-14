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

int main() {

    //fRead("in.txt");
    //fWrite("out.txt");

    string binaryInt, revBinary;
    LLI i, n, Count;
    while(cin >> n) {
        if (n == 0) break;
        Count = 0;
        i = 1;
        binaryInt = "";
        revBinary = "";
        cout << "The parity of ";
        while(i <= n) {
            if (n & i) {
                ++Count;
                binaryInt += '1';
            }
            else {
                binaryInt += '0';
            }
            i <<= 1;
        }
        //printf("%s ", binaryInt.c_str());
        for (i = binaryInt.size() - 1; i >= 0; --i) {
            //putchar(binaryInt[i]);
            revBinary += binaryInt[i];

        }
        cout << revBinary;
        cout << " is " << Count << " (mod 2)." << endl;
    }


    return (0);
}
