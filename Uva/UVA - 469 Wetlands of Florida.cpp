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
#define N 105
string grid[N];

int are[N][N], conn, row, col;

struct pos{
    int x, y;
};

bool isValid(pos cur) {

    if (cur.x < 0 || cur.y < 0) return false;
    if (cur.x > row - 1 || cur.y > col - 1)
        return false;

    if (are[cur.x][cur.y] == 1 || grid[cur.x][cur.y] == 'L') {
        return false;
    }
    if(grid[cur.x][cur.y] == 'W')
        return true;
    return false;
}

int bfsFind(pos cur) {
    queue < pos > q;
    q.push(cur);
    pos temp;
    int i, Count = 1;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (i = 0; i < 8; ++i) {
            temp.x = cur.x + dir[0][i];
            temp.y = cur.y + dir[1][i];
            if (isValid(temp)) {
                ++Count;
                are[temp.x][temp.y] = 1;
                q.push(temp);
                //cout << "Entering " << temp.x << " " << temp.y << endl;
            }
        }
    }
    return Count;
}

int main() {
    //FastRead

    //fRead("in.txt");
    //fWrite("out.txt");
    int test, i, j, x, y, t = 0, xx, yy;
    pos temp;
    string s;
    cin >> test;
    cin.ignore();
    getline(cin, s);
    while(test--) {
        if (t > 0) puts("");
        ++t;
        row = col = 0;
        //memset(are, 0, sizeof(are));
        while(getline(cin,s)) {
            //cout << s << endl;
            if(s == "") break;
            if (s[0] == 'L' || s[0] == 'W'){
                grid[row++] = s;
                xx = s.size();
                col = max(col,xx);
            }
            else {
                memset(are, 0, sizeof(are));
                stringstream ss(s);
                while(ss >> xx) {
                    ss >> yy;
                    temp.x = xx - 1;
                    temp.y = yy - 1;
                    are[temp.x][temp.y] = 1;
                    xx = bfsFind(temp);
                    printf("%d\n", xx);
                }
            }
        }
    }

    return (0);
}
