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

char sol[200][10];
char temp[10];
bool row[10];
bool rightDiag[20];
bool leftDiag[20];
int length;

void generateSol(int n) {
    if (n == 8) {
        temp[8] = 0;
        strcpy(sol[length], temp);
        ++length;
        return;
    }
    int i;
    for (i = 0; i < 8; i++) {
        if (row[i] && rightDiag[n - i + 8] && leftDiag[n + i]) {
            row[i] = rightDiag[n - i + 8] = leftDiag[n + i] = false;
            temp[n] = i + '1';
            generateSol(n + 1);
            row[i] = rightDiag[n - i + 8] = leftDiag[n + i] = true;
        }
    }
}

int main() {
    //FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    memset(row, true, sizeof(row));
    memset(rightDiag, true, sizeof(rightDiag));
    memset(leftDiag, true, sizeof(leftDiag));
    length = 0;

    generateSol(0);

    int test, r, c, cases = 0, i, j;
    cin >> test;

    bool blank = false;
    while(test--) {
        cases = 0;
        cin >> r >> c;
        if (blank) cout << endl;
        blank = true;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8\n" << endl;

        for (i = 0; i < length; ++i) {
            if (sol[i][c - 1] == r + '0') {
                printf("%2d      ", ++cases);
                printf("%c", sol[i][0]);
                for(j = 1; j < 8; ++j) {
                    printf(" %c", sol[i][j]);
                }
                printf("\n");
            }
        }
    }

    return (0);
}
