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

//int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
//                  {0,-1,1,0,-1,1,1,-1}};

//int knight[2][8] = {{-2,-2,-1,1,2,2,1,-1},
//                    {-1,1,2,2,1,-1,-2,-2}};
//bool sevenSegment[8][10] =
//{
//    {0,0,0,0,0,0,0,0,0,0}, ///Segment 0
//    {1,0,1,1,0,1,1,1,1,1}, ///Segment 1
//    {1,1,1,1,1,0,0,1,1,1}, ///Segment 2
//    {1,1,0,1,1,1,1,1,1,1}, ///Segment 3
//    {1,0,1,1,0,1,1,0,1,1}, ///Segment 4
//    {1,0,1,0,0,0,1,0,1,0}, ///Segment 5
//    {1,0,0,0,1,1,1,0,1,1}, ///Segment 6
//    {0,0,1,1,1,1,1,0,1,1}  ///Segment 7
//};
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(NULL);

///======================== Let's GO ========================
struct process {

    LLI time;
    char type;
    process() {
        time = 0;
        type = 'a';
    }
    process(LLI st, char c) {
        time = st;
        type = c;
    }
    void modify(LLI st, char c) {
        time = st;
        type = c;
    }
    bool operator < (const process & p) {
        if (time < p.time) return true;
        else if (time == p.time) {
            if (type == 's') return true;
        }
        return false;
    }
    void operator = (const process & p) {
        time = p.time;
        type = p.type;
    }
};
bool comp(const process & o, const process & p) {
    if (o.time < p.time) return true;
        else if (o.time == p.time) {
            if (o.type == 's') return true;
        }
        return false;
}
int main() {
    //FastRead
    process aProcess;
    vector < process > proContainer;
    LLI test, t, n, i, x, y, minNeed, running, range;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        proContainer.clear();
        scanf("%lld", &n);
        for (i = 0; i < n; ++i) {
            scanf("%lld %lld", &x, &y);
            aProcess.modify(x, 's');
            proContainer.phb(aProcess);
            aProcess.modify(y, 'e');
            proContainer.phb(aProcess);
        }
        sort(proContainer.begin(), proContainer.end(), comp);
        minNeed = running = 0;
        range = proContainer.size();
        for (i = 0; i < range; ++i) {
            if (proContainer[i].type == 's')
                ++running;
            else if (proContainer[i].type == 'e')
                --running;
            if (minNeed < running) minNeed = running;
        }
        printf("Case %lld: %lld\n", t, minNeed);
    }

    return (0);
}
