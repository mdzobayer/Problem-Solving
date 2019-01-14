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
#define FastRead std::ios::sync_with_stdio(false);cin.tie(NULL);

///======================== Let's GO ========================

int main() {
    FastRead

    fRead("in.txt");

    vector <int> vt;
    int n, m, x, j, y, inDegree[110], i, currentTask;
    while(cin >> n >> m) {

        if (n == 0 && m == 0) break;

        vt.clear();
        queue<int> q;
        vector <int> matrix[110];
        memset(inDegree, 0, sizeof(inDegree));

        for (i = 0; i < m; ++i) {
            cin >> x >> y;
            matrix[x].phb(y);
            inDegree[y] += 1;
        }
        for (i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        /// Now main Process
        while(!q.empty()) {
            currentTask = q.front();
            q.pop();

            vt.phb(currentTask);
            for (j = 0; j < matrix[currentTask].size(); ++j) {
                --inDegree[matrix[currentTask][j]];
                if (inDegree[matrix[currentTask][j]] == 0) {
                    q.push(matrix[currentTask][j]);
                }
            }
        }
        for (int i : vt) {
            printf("%d", i);
            if (vt.back() != i)
                printf(" ");
        }
        printf("\n");
    }

    return (0);
}
