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
    char act;
    int ro, co, level;
    point(char ch, int r, int c, int le) {
        act = ch;
        ro = r;
        co = c;
        level = le;
    }
    point() {
        act = 'J';
        ro = 0;
        co = 0;
        level = 0;
    }
    void modify(char ch, int r, int c, int le) {
        act = ch;
        ro = r;
        co = c;
        level = le;
    }
    void operator = (point p) {
        this->act = p.act;
        this->ro = p.ro;
        this->co = p.co;
        this->level = p.level;
        //return *this;
    }
};

int row, col;
int dir[2][4] =
                {{-1, 0, 0, 1},
                  {0, -1, 1, 0}
                };
char str[1000+10][1000+10];


bool isValid(point & p) {
    if ( p.ro < 0 || p.co < 0 || p.ro >= row || p.co >= col) {
        return false;
    }
    else if (str[p.ro][p.co] == '.')
        return true;
    else if (str[p.ro][p.co] == 'J' && p.act == 'F')
        return true;

    return false;
}
bool isOut(point & p) {
    if ( p.ro < 0 || p.co < 0 || p.ro >= row || p.co >= col) {
        return true;
    }
    return false;
}

int bfs() {
    int i, j, joeCount, activePos = 0;

    queue<point> q;
    point jPoint, current, tempPoint;
    /// Finding Joe and Fire
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (str[i][j] == 'F') {
                tempPoint.modify('F', i, j, 0);
                q.push(tempPoint);
            }
            else if (str[i][j] == 'J') {
                jPoint.modify('J', i, j, 0);
                ++activePos;
            }
            else if (str[i][j] == '.') {
                ++activePos;
            }
        }
    }
    //printf("Active Position %d\n", activePos);
    q.push(jPoint);
    joeCount = 1;
    /// BFS Processing
    while(!q.empty()) {
        current = q.front();
        //printf("act %c level %d pos %d %d\n", current.act, current.level, current.ro, current.co);
        if (current.act == 'J') {
            --joeCount;
        }
        q.pop();
        if (current.act == 'J') {
            for (i = 0; i < 4; ++i) {
                tempPoint.modify('J', current.ro + dir[0][i], current.co + dir[1][i], current.level + 1);
                //cout << "direction testing";
                //cout << " " << tempPoint.ro << " " << tempPoint.co << endl;
                if(isOut(tempPoint)) {
                    return tempPoint.level;
                }
                else if (isValid(tempPoint)){
                    //cout << "here";
                    //cout << " " << tempPoint.ro << " " << tempPoint.co << endl;
                    q.push(tempPoint);
                    ++joeCount;
                    str[tempPoint.ro][tempPoint.co] = 'J';
                }
            }
        }
        else {
            for (i = 0; i < 4; ++i) {
                tempPoint.modify('F', current.ro + dir[0][i], current.co + dir[1][i], current.level + 1);
                //cout << "direction testing";
                //cout << " " << tempPoint.ro << " " << tempPoint.co << endl;
                if (isValid(tempPoint)) {
                    q.push(tempPoint);
                    //if (str[tempPoint.ro][tempPoint.co] != 'J')
                        --activePos;
                    str[tempPoint.ro][tempPoint.co] = 'F';
                }
            }
        }
        /*
        for (i = 0; i < row; ++i) {
            printf("%s\n", str[i]);
        }
        */
        //cout << "Active pos " << activePos << " joeCount " << joeCount << endl;
        if (joeCount == 0)
            return 0;
    }
}



int main() {


    fRead("in.txt");
    fWrite("out.txt");

    int test, i, result, t = 0;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d", &row, &col);

        getchar();
        for (i = 0; i < row; ++i) {
            scanf("%s", &str[i]);
        }
        result = bfs();
        printf("Case %d: ", ++t);
        if (result == 0) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", result);
        }
        //line += (row + 1);
    }

    return (0);
}
