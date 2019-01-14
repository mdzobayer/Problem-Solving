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

vector < string > grid;
vector < vector < bool > > are;
LLI conn[130], row, col;

struct pos{
    LLI x, y;
};
struct name{
    LLI no;
    char ch;

    bool operator < (name t) {
        if (this->no > t.no) return true;
        else if (this->no < t.no) return false;
        else if (this->ch <= t.ch) return true;
        else return false;
    }
};

bool isValid(pos cur, char ch) {

    if (cur.x < 0 || cur.y < 0) return false;
    if (cur.x > row - 1 || cur.y > col - 1)
        return false;

    if (are[cur.x][cur.y] == 1 || grid[cur.x][cur.y] != ch) {
        return false;
    }
    if(grid[cur.x][cur.y] == ch)
        return true;
    return false;
}

void bfsFind(pos cur) {
    queue < pos > q;
    q.push(cur);
    pos temp;
    LLI i;
    char ch = grid[cur.x][cur.y];
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (i = 0; i < 4; ++i) {
            temp.x = cur.x + dir[0][i];
            temp.y = cur.y + dir[1][i];
            if (isValid(temp, ch)) {
                are[temp.x][temp.y] = 1;
                q.push(temp);
                //cout << "Entering " << temp.x << " " << temp.y << endl;
            }
        }
    }
}

int main() {
    //FastRead

    //fRead("in.txt");
    //fWrite("out.txt");
    LLI test, i, j, x, y, t = 0, xx, yy;
    pos temp;
    name tempL;
    string s;
    char ch;
    vector < name > order;
    scanf("%lld", &test);
    getchar();
    while(test--) {
        ++t;
        grid.clear();
        are.clear();
        order.clear();
        memset(conn, 0, sizeof(conn));

        scanf("%lld %lld", &row, &col);
        getchar();
        vector < bool > tmp(col+5, 0);

        for (i = 0; i < row; ++i) {
            getline(cin, s);
            grid.push_back(s);
            are.push_back(tmp);
        }
        are.push_back(tmp);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < col; ++j) {
                if (are[i][j] == 0) {
                    are[i][j] = 1;
                    ch = grid[i][j];
                    temp.x = i;
                    temp.y = j;
                    ++conn[ch];
                    bfsFind(temp);
                }
            }
        }
        for (i = 'a'; i <= 'z'; ++i) {
            tempL.no = conn[i];
            tempL.ch = i;
            order.push_back(tempL);
        }
        sort(order.begin(), order.end());
        printf("World #%lld\n", t);
        for (i = 0; i < order.size(); ++i) {
            if (order[i].no == 0) break;
            printf("%c: %lld\n", order[i].ch, order[i].no);
        }
    }

    return (0);
}
