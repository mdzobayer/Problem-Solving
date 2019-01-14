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

int color[210];
bool visited[210];

int main() {
    FastRead

    fRead("in.txt");

    bool flag;
    int n, l, i, x, y, j;
    while(cin >> n) {
        if (n == 0) break;
        flag = true;
        vector<int> matrix[210];
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        cin >> l;
        for (i = 0; i < l; ++i) {
            cin >> x >> y;
            matrix[x].phb(y);
            matrix[y].phb(x);
        }
        for (i = 0; i < n; ++i) {
            queue<int> q;
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                color[i] = 1;
            }
            while(!q.empty()) {
                x = q.front();
                q.pop();
                for (j = 0; j < matrix[x].size(); ++j) {
                    if (color[x] == color[matrix[x][j]]) {
                        /// Not Bicolorable
                        flag = false;
                        goto end;
                    }
                    else if (visited[matrix[x][j]] == 0) {
                        q.push(matrix[x][j]);
                        visited[matrix[x][j]] = 1;
                        color[matrix[x][j]] = color[x] + 1;
                        if (color[matrix[x][j]] > 4) color[matrix[x][j]] = 1;
                        //cout << "Pushed " << matrix[x][j] << " Color is " << color[matrix[x][j]] << endl;
                    }
                }
            }
        }
        end:
        if (flag) {
            printf("BICOLORABLE.\n");
        }
        else {
            printf("NOT BICOLORABLE.\n");
        }
    }

    return (0);
}
