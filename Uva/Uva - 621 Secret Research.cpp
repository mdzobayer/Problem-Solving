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

    int n, i;
    string s;
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        cin >> s;
        if (s == "1" || s == "4" || s == "78"){
            cout << "+" << endl;
        }
        else if (s[s.size() - 1] == '5' && s[s.size() - 2] == '3') {
            cout << "-" << endl;
        }
        else if (s[0] == '9' && s[s.size() - 1] == '4') {
            cout << "*" << endl;
        }
        else if (s[0] == '1' && s[1] == '9' && s[2] == '0') {
            cout << "?" << endl;
        }
        else {
            if (s[s.size() - 1] == '5' || s[s.size() - 2] == '3') {
                cout << "-" << endl;
            }
            else if (s[0] == '9' || s[s.size() - 1] == '4') {
                cout << "*" << endl;
            }
            else if (s[0] == '1' || s[1] == '9' || s[2] == '0') {
                cout << "?" << endl;
            }
            else {
                cout << "+" << endl;
            }
        }
    }

    return (0);
}
