#include <bits/stdc++.h>
#include <stdlib.h>
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

vector<int> agList[100000+10];
int level[100000+10];
bool flag[100000+10];

int main() {
    FastRead

    //fRead("in.txt");

    int test, i, j, n, u, v, curr, t = 0;
    cin >> test;
    while(test--) {
        cin >> n;
        /// must reset vector
        for (i = 0; i <= n+1; ++i) {
            agList[i].clear();
            flag[i] = false;
            level[i] = 0;
        }

        if (t > 0) puts("");
        ++t;
        for (i = 1; i <= n; ++i) {
            cin >> u >> v;
            while(v--) {
                cin >> curr;
                agList[u].phb(curr);
            }
        }
        //cout << "I am here" << endl;
        cin >> u >> v;
         //cout << u << " " << v << endl;
        queue<int> q;
        q.push(u);
        level[u] = 0;
        flag[u] = true;

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            for (i = 0; i < agList[curr].size(); ++i) {
                if (flag[agList[curr][i]] == 0) {
                    flag[agList[curr][i]] = 1;
                    level[agList[curr][i]] = level[curr] + 1;
                    q.push(agList[curr][i]);
                    if (agList[curr][i] == v) {
                        goto End;
                    }
                }
            }
        }
        End:
        //if (check) {
            printf("%d %d %d\n", u, v, level[v] - 1);
        //}
    }

    return (0);
}
