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
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    int i, sum = 0, noLine = 0, j;
    string s;
    while(getline(cin, s)) {
        //cout << "---- " << s << endl;
        if (s == "") {
            if (noLine) putchar('\n');
            continue;
        }
        noLine = 1;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                sum += (s[i] - '0');
            }
            else if (s[i] == 'b') {
                for (j = 0; j < sum; ++j) {
                    putchar(' ');
                }
                sum = 0;
            }
            else if (s[i] == '!') {
                putchar('\n');
                sum = 0;
            }
            else {
                for (j = 0; j < sum; ++j) {
                    putchar(s[i]);
                }
                sum = 0;
            }
        }
        putchar('\n');


    }

    return (0);
}
