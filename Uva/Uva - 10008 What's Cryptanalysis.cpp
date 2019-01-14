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

struct letter{
    int pos, value;

    bool operator < (letter t) {
        if (this->value > t.value)
            return true;
        else if (this->value == t.value) {
            return (this->pos < t.pos);
        }
        else return false;
    }
};

int main() {
    FastRead

    //fRead("in.txt");

    letter le;

    vector< letter > vt;
    int n, j, i;
    int lett[30];
    memset(lett, 0, sizeof(lett));
    char str[1024];

    scanf("%d", &n);
    getchar();
    for( i = 0; i < n; ++i) {
        gets(str);
        for (j = 0; str[j]; ++j) {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                ++lett[str[j] - 'A'];
            }
            else if (str[j] >= 'a' && str[j] <= 'z') {
                ++lett[str[j] - 'a'];
            }
        }
    }
    for (i = 0; i < 26; ++i) {
        if (lett[i] > 0){
            le.pos = i;
            le.value = lett[i];
            vt.phb(le);
        }
    }
    sort(vt.begin(), vt.end());

    for (i = 0; i < vt.size(); ++i) {
        printf("%c %d\n", vt[i].pos + 'A', vt[i].value);
    }


    return (0);
}
