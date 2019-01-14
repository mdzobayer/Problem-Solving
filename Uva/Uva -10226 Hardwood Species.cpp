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

    //fRead("in.txt");
    //fWrite("out.txt");

    map<string, LLI> species;
    LLI test, Count, t = 1;
    long double res;
    string s;
    cin >> test;
    cin.ignore();
    getline(cin, s);

    while(test--) {
        if (t != 1) cout << endl;
        ++t;
        species.clear();
        Count = 0;
        while(getline(cin, s)) {
            if (s == "") {
                break;
            }
            ++Count;
            if (species.find(s) != species.end())
                species[s] += 1;
            else
                species[s] = 1;
        }
        res = 100.0 / Count;
        cout << setprecision(4) << fixed;
        for ( map<string, LLI>::iterator it = species.begin(); it != species.end(); ++it) {

            cout << it->first << " "  << it->second * res << endl;
            //printf("%s %0.4lf\n", it->first.c_str(), res);
        }
    }

    return (0);
}
