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


    int test, n, i, index, p;
    cin >> test;
    while(test--) {
        cin >> n;
        cin.ignore();
        p = 0;
        string ins[105], s;
        for (i = 1; i <= n; ++i) {
            getline(cin, s);
            if (s[0] == 'S') {
                stringstream ss(s);
                ss >> s;
                ss >> s;
                ss >> index;
                ins[i] = ins[index];
                if (ins[i] == "LEFT") {
                    p -= 1;
                }
                else {
                    p += 1;
                }
            }
            else if (s == "LEFT"){
                ins[i] = s;
                p -= 1;
            }
            else {
                p += 1;
            }
        }
        printf("%d\n", p);
    }

    return (0);
}
