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
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int main() {
    FastRead

    //fRead("in.txt");

    double ch[300], sum;
    LLI test, k, m, temp, i, j;
    char character;
    string s;
    while(cin >> test) {
        cin.ignore();
        while(test--) {
            memset(ch, 0, sizeof(ch));
            cin >> k;
            cin.ignore();
            for (i = 0; i < k; ++i) {
                //scanf("%c", &character);
                cin >> character;
                cin >> temp;
                cin.ignore();
                ch[character] = temp;
            }
            sum = 0.0;
            cin >> m;
            cin.ignore();
            for (i = 0; i < m; ++i) {
                getline(cin, s);
                for (j = 0; j < s.size(); ++j) {
                    sum += ch[s[j]];
                }
            }
            //setprecision(2);
            //cout << sum/100.0 << "$" << endl;
            printf("%0.2f$\n", sum/100.0);
        }
    }
    return (0);
}
