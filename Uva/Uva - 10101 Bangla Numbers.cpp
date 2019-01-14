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

    int i, pro[4], step, Count, test = 0;
    string s[4], str, finalStr;
    s[0] = "atahs";
    s[1] = "rajah";
    s[2] = "hkal";
    s[3] = "ituk";
    pro[0] = 2;
    pro[1] = 1;
    pro[2] = 2;
    pro[3] = 2;

    while(cin >> str) {
        finalStr = "";
        step = 0;
        Count = 0;
        for (i = str.size() - 1; i >=  0; --i) {
            if (Count >= pro[step]) {
                    finalStr += ' ';
                finalStr += s[step];
                    finalStr += ' ';
                ++step;
                if (step > 3) step = 0;
                Count = 0;
            }
            ++Count;
            if (str[i] == '0') continue;
            finalStr += str[i];
        }
        printf("%d. ", ++test);
        for (i = finalStr.size() - 1; i >= 0; --i) {
            printf("%c", finalStr[i]);
        }
        printf("\n");
    }

    return (0);
}
