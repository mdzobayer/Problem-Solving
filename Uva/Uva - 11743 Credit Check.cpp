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

int sumOfDigit(int x) {
    int sum = 0;
    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main() {
    FastRead
    string s;
    LLI n, i, j, sum1, sum2;
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        sum1 = sum2 = 0;
        for (j = 0; j < 4; ++j) {
            cin >> s;
            sum2 += (s[1] - '0');
            sum2 += (s[3] - '0');
            sum1 += sumOfDigit((s[0] - '0') * 2);
            sum1 += sumOfDigit((s[2] - '0') * 2);
        }
        cin.ignore();
        sum1 += sum2;
        if (sum1 % 10 == 0) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }

    return (0);
}
