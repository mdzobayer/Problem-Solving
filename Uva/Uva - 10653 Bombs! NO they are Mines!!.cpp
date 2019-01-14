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

class point{
public:
    int ro, co, level;
    point(){
        ro = 0; co = 0; level = 0;
    }
    point(int r, int c, int le) {
        ro = r; co = c; level = le;
    }
    void modify(int r, int c, int le) {
        ro = r; co = c; level = le;
    }
    void operator = (point p) {
        this->ro = p.ro;
        this->co = p.co;
        this->level = p.level;
    }
    bool operator == (point p) {
        if (this->ro == p.ro && this->co == p.co)
            return true;
        return false;
    }
};

int dir[2][4] =
                {{-1, 0, 0, 1},
                  {0, -1, 1, 0}
                };

int grid[1000+10][1000+10], row, col ;

bool isValid(point &p) {
    if (p.ro < 0 || p.co < 0 || p.ro >= row || p.co >= col)
        return false;
    else if (grid[p.ro][p.co] == 0) return false;
    return true;
}
point start, desti, curr, tempPoint;
int bfs() {
    int i, j;

    queue<point> q;
    grid[start.ro][start.co] = 0;
    q.push(start);

    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for (i = 0; i < 4; ++i) {
            tempPoint.modify(curr.ro + dir[0][i], curr.co + dir[1][i], curr.level + 1);
            if (isValid(tempPoint)){
                if (tempPoint == desti) {

                    return tempPoint.level;
                }
                //cout << "------" << tempPoint.ro << " " << tempPoint.co << " leve " << tempPoint.level << endl;
                grid[tempPoint.ro][tempPoint.co] = 0;
                q.push(tempPoint);
            }
        }
    }
    return 0;
}

int main() {
    FastRead

    //fRead("in.txt");

    int i , j, r, c, rowBomb, colBomb, bomb, result;
    while(cin >> row >> col) {
        if (row == 0 && col == 0) continue;
        // Reset grid
        memset(grid, 1, sizeof(grid));

        cin >> rowBomb;
        for (i = 0; i < rowBomb; ++i) {
            cin >> r >> colBomb;
            //cout << "r is " << r << endl;
            for (j = 0; j < colBomb; ++j) {
                cin >> bomb;
                grid[r][bomb] = 0;
            }
        }
        /// Input for source and destinition
        cin >> r >> c;
        start.modify(r, c, 0);
        //cout << start.ro << " start " << start.co << endl;
        cin >> r >> c;
        desti.modify(r, c, 0);
        //cout << desti.ro << " desti " << desti.co << endl;
        result = bfs();
        printf("%d\n", result);
    }

    return (0);
}
