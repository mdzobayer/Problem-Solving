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

    map<string, LLI> dictonary;
    string s, word, line;

    int m, n, i, j;
    LLI salary;
    ULL total;

    while(cin >> m >> n) {
        dictonary.clear();
        for (i = 0; i < m; ++i) {
            cin.ignore();
            cin >> s;
            cin >> salary;
            dictonary[s] = salary;
        }
        cin.ignore();

        for (i = 0; i < n; ++i) {
            total = 0;
            while(getline(cin, line)) {
                /// Description Ending
                if (line == ".") break;

                stringstream wordExtractor(line);
                while(wordExtractor >> word) {
                    if (dictonary.find(word) != dictonary.end()) {
                        total += dictonary[word];
                    }
                }
            }
            cout << total << endl;
        }
    }

    return (0);
}
