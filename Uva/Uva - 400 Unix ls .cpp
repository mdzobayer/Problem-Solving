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

    fRead("in.txt");
    //fWrite("out.txt");

    string s;
    int n, i, maximumLen, justify, rows, j, k, column;
    vector <string> vt;

    while(cin >> n) {
        cin.ignore();
        vt.clear();
        maximumLen = 0;
        for (i = 0; i < n; ++i) {
            cin >> s;
            if (maximumLen < s.length()) {
                maximumLen = s.length();
            }
            vt.phb(s);
        }
        sort(vt.begin(), vt.end());
        column = maximumLen + 2;
        justify = 62 / column;
        rows = ceil(n /(double)justify);


        //cout << "Row " << rows<< " Justify " << justify << endl;
        cout << "------------------------------------------------------------" << endl;
        for (i = 0; i < rows; ++i) {
            for (j = i; j < vt.size(); j += rows) {
                cout << vt[j];
                if (j + rows  < vt.size()) {
                    for (k = vt[j].size(); k <= column; ++k) {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }

    return (0);
}
