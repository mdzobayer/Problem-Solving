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

class position{
public:
    int x, y;
    position () {
        x = 0;
        y = 0;
    }
    position(int a, int b) {
        x = a;
        y = b;
    }
    void operator = (position p) {
        this->x = p.x;
        this->y = p.y;
    }
};

char plot[105][105];
bool visited[105][105];
int n, m, i, j, Count;

bool checkAPlot(int x, int y) {
    if (x < 0 || y < 0) return false;
    else if (x >= n || y >= m) return false;
    else if (plot[x][y] == '@' && visited[x][y] == 0) {
        visited[x][y] = 1;
        return true;
    }
    else return false;
}
//bool checkAdjacent() {
//    return (checkAPlot(i - 1, j - 1) || checkAPlot(i - 1, j) ||
//            checkAPlot(i - 1, j + 1) || checkAPlot(i, j - 1));
//}

int main() {
    FastRead

    //fRead("in.txt");
    position tempPos;
    while(cin >> n >> m) {
        cin.ignore();
        if (n == 0 && m == 0) break;
        memset(visited, 0, sizeof(visited));
        for (i = 0; i < n; ++i) {
            cin >> plot[i];
        }
        Count = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (plot[i][j] == '@' && visited[i][j] == 0) {
                    ++Count;
                    /// Now bfs
                    queue <position> q;
                    visited[i][j] = 1;
                    position pos(i,j);
                    q.push(pos);
                    //cout << "i " << i << " and j is " << j << endl;
                    while(!q.empty()) {
                        pos = q.front();
                        q.pop();
                        if (checkAPlot(pos.x - 1, pos.y - 1)) {
                            tempPos.x = pos.x - 1;
                            tempPos.y = pos.y - 1;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x - 1, pos.y)) {
                            tempPos.x = pos.x - 1;
                            tempPos.y = pos.y;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x - 1, pos.y + 1)) {
                            tempPos.x = pos.x - 1;
                            tempPos.y = pos.y + 1;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x , pos.y + 1)) {
                            tempPos.x = pos.x;
                            tempPos.y = pos.y + 1;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x + 1, pos.y + 1)) {
                            tempPos.x = pos.x + 1;
                            tempPos.y = pos.y + 1;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x + 1, pos.y)) {
                            tempPos.x = pos.x + 1;
                            tempPos.y = pos.y;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x + 1, pos.y - 1)) {
                            tempPos.x = pos.x + 1;
                            tempPos.y = pos.y - 1;
                            q.push(tempPos);
                        }
                        if (checkAPlot(pos.x, pos.y - 1)) {
                            tempPos.x = pos.x;
                            tempPos.y = pos.y - 1;
                            q.push(tempPos);
                        }
                    }
                }
            }
        }
        cout << Count << endl;
    }

    return (0);
}
