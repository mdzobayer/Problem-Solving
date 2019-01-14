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
    char str[2000000+5], age;
    int n, i, minDis, dis;
    while(scanf("%d", &n) == 1) {
        getchar();
        if (n == 0) break;
        scanf("%s", &str);
        age = '.';
        minDis = 2000005;
        dis = 0;
        for (i = 0; i < n; ++i) {
            if (str[i] == 'Z') {
                minDis = 0;
                break;
            }
            else if (str[i] == 'R') {
                if (age == 'R') dis = 0;
                else if (age == 'D') {
                    ++dis;
                    //printf("Hello1\n");
                    minDis = min(dis, minDis);
                    age = 'R';
                    dis = 0;
                }
                else {
                    age = 'R';
                    dis = 0;
                }
            }
            else if (str[i] == 'D') {
                if (age == 'D') dis = 0;
                else if (age == 'R') {
                    //printf("Hello2\n");
                    ++dis;
                    minDis = min(dis, minDis);
                    age = 'D';
                    dis = 0;
                }
                else {
                    age = 'D';
                    dis = 0;
                }
            }
            else if (str[i] == '.') {
                if (age != '.') {
                    ++dis;
                }
                else {
                    dis = 0;
                }
            }
        }
        printf("%d\n", minDis);
    }

    return (0);
}