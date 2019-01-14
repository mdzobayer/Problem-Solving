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
    vector<int> nm;
    string s, temps;
    LLI test, i, temp, k = 0;
    cin >> test;
    cin.ignore();
    while(test--) {
        if (k > 0) cout << endl;
        ++k;
        nm.clear();
        getline(cin, s);
        getline(cin, s);
        stringstream ss(s);
        while(ss >> temp) {
            nm.push_back(temp);
        }
        vector<string> vss(nm.size() + 5);
        getline(cin, s);
        stringstream sss(s);
        i = 0;
        while(sss >> temps) {
            vss[nm[i]] = temps;
            ++i;
        }
        for (i = 1; i <= nm.size(); ++i) {
            cout << vss[i] << endl;
        }
    }

    return (0);
}
