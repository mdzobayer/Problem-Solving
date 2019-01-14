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

    int test, t, n, k, i, recog;
    int recognize[100];
    string s;

    cin >> test;
    for (t = 1; t <= test; ++t) {
        recog = 0;
        queue<int> q;

        cin >> n;
        cin >> k;
        cin >> s;
        memset(recognize, 0, sizeof(recognize));
        for (i = 0; i < s.size(); ++i) {
            if (recognize[s[i]]) {
                ++recog;
            }

            if (i >= k) {
                recognize[q.front()] -= 1;
                q.pop();
            }
            recognize[s[i]] += 1;
            q.push((int)s[i]);
        }
        printf("Case %d: %d\n", t, recog);
    }

    return (0);
}
