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

struct Register {
    string id;
    int line;
    string binary;
};

void findDecimal (Register & rs, ULL & sum) {
    ULL j = 1;
    LLI i;
    for ( i = rs.binary.size()-1; i >= 0; --i) {
        if (rs.binary[i] == '1') {
            sum += j;
        }
        j <<= 1;
    }
}

int main() {
    FastRead

    //fRead("in.txt");

    ULL sum;
    int b, v, i, j, k, q;
    string s, s2="";
    Register tempR;
    tempR.binary = "";

    vector<Register> container;

    map<string, ULL> result;

    while(cin >> b >> v) {

        container.clear();
        result.clear();

        for (i = 0; i < v; ++i) {
            cin.ignore();
            cin >> tempR.id;
            cin >> tempR.line;
            container.phb( tempR);
        }
        for (i = 0; i < container.size(); ++i) {
            for (j = 0; j < container[i].line; ++j) {
                cin.ignore();
                cin >> s;
                container[i].binary += s;
            }
        }

        for (i = 0; i < container.size(); ++i) {
             sum = 0;
             findDecimal(container[i], sum);
             result[container[i].id] = sum;
        }

        cin >> q;
        for (i = 0; i < q; ++i) {
            cin.ignore();
            cin >> s;
            cout << s << "=";
            if (result.find(s) != result.end()) {
                cout << result[s];
            }
            cout << endl;
        }
    }

    return (0);
}
