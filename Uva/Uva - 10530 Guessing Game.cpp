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

    int n;
    bool flag = true;
    string s;
    int tooHigh = 15, tooLow = -1;
    while(cin >> n) {
        if (n == 0) break;
        cin.ignore();
        getline(cin, s);
        if (s == "right on") {
            //cout << tooLow << " " << n << " " << tooHigh << endl;
            if (flag && n < tooHigh && n > tooLow) {
                cout << "Stan may be honest" << endl;
            }
            else {
                cout << "Stan is dishonest" << endl;
            }
            flag = true;
            tooHigh = 15;
            tooLow = -1;
        }
        else if (s == "too high") {
            if (tooHigh > n)
                tooHigh = n;
        }
        else if (s == "too low") {
            if (tooLow < n)
                tooLow = n;
        }
        if ((tooHigh == tooLow + 1) || (tooHigh <= tooLow)) {
            flag = false;
        }
    }

    return (0);
}
