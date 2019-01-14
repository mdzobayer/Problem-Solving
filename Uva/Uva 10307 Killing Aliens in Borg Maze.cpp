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

int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};

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
#define N 60
struct area {
    int step, lastFound, xx, yy;

    area() {
        step = 0;
        lastFound = 0;
        xx = yy = 0;
    }
    void modify(int s, int l, int x, int y) {
        step = s;
        lastFound = l;
        xx = x;
        yy = y;
    }
    void operator = (area r) {
        this->step = r.step;
        this->lastFound = r.lastFound;
        this->xx = r.xx;
        this->yy = r.yy;
    }
};

bool visited[N][N];
string grid[N];

int row, col;

bool isAviable(area a) {
    if (a.xx < 0 || a.yy < 0 || a.xx > row - 1 || a.yy > col - 1)
        return false;
    if (grid[a.xx][a.yy] == '#' || visited[a.xx][a.yy] == false)
        return false;

    return true;
}
int countDistance(int sx, int sy) {
    area tempArea, curr;
    tempArea.modify(0, 0, sx, sy);
    cout << "Crush 2" << endl;
    queue<area> qt;
    qt.push(tempArea);
    cout << "Crush 3 " << sx << " " << sy << endl;
    visited[sx][sy] = false;
    cout << "Crush 4" << endl;
    int i, cost = 0;
    bool foundNext;
    while(!qt.empty()) {

        curr = qt.front();
        qt.pop();
        foundNext = false;
        for (i = 0; i < 4; ++i) {
            tempArea.modify(curr.step + 1,curr.lastFound, curr.xx + dir[0][i], curr.yy + dir[1][i]);
            if (isAviable(tempArea)) {
                visited[tempArea.xx][tempArea.yy] = false;
                if (grid[tempArea.xx][tempArea.yy] == 'A') {
                    if (foundNext)
                        cost += 2;
                    else
                        cost += tempArea.step - tempArea.lastFound;
                    tempArea.lastFound = tempArea.step;
                    foundNext = true;
                }
                qt.push(tempArea);
            }
        }
    }
    return cost;
}
int main() {
    //FastRead

    fRead("in.txt");

    int test, t, i, j, x, y;
    cin >> test;

    for (t = 0; t < test; ++t) {
        cin >> col >> row;
        cin.ignore();
        for (i = 0; i < row; ++i) {

            getline(cin,grid[i]);

        }
        for (i = 0; i < row; ++i) {
            for (j = 0; j < col; ++j) {
                if (grid[i][j] == 'S') {
                    x = i; y = j;
                }
                visited[i][j] = true;
            }
        }
        cout << countDistance(x, y) << endl;
    }

    return (0);
}
