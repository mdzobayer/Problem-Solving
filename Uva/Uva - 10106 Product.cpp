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

namespace patch {
    template < typename T> std::string to_string(const T &n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}
using namespace patch;
using namespace std;

string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();

    if (n1 == 0 || n2 == 0) return "0";

    vector<int> result(n1 + n2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = n1 - 1; i >= 0; --i) {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = n2-1; j >= 0; --j) {
            int n2 = num2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        ++i_n1;
    }

    int i = result.size() - 1;
    while(i >= 0 && result[i] == 0) {
        --i;
    }
    if (i == -1) return "0";

    string s = "";
    while(i >= 0) {
        s += to_string(result[i--]);
    }

    return s;
}

int main() {
    FastRead
    //fRead("in.txt");
    string s1, s2;

    while(cin >> s1 >> s2) {
        cout << multiply(s1, s2) << endl;
    }

    return (0);
}
