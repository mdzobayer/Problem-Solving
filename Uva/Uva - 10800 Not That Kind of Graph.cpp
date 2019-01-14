#include <bits/stdc++.h>
#define ll long long int
#define SIZE 55
using namespace std;

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test, t, mxRow, mxCol, row, col, i, j;
    char str[SIZE][SIZE];
    string s;
    cin >> test;
    for (t = 0; t < test; ++t) {
        cin.ignore();
        cin >> s;
        for (i = 0;i < SIZE; ++i) {
            for (j = 0; j < SIZE; ++j) {
                str[i][j] = ' ';
            }
        }
        mxRow = mxCol = -1;
        row = col = 0;
        mxCol = s.size();
        for (i = 0; i < mxCol; ++i) {
            if (s[i] == 'R') {
                ++row;
            }
            else if (s[i] == 'F') {
                --row;
            }
            if (mxRow < row) mxRow = row;
        }
        row = ++mxRow;
        //cout << "row = " << row << endl;
        col = 1;
        for (i = 0; i < mxCol; ++i) {
            //printf("Row col = %c %d %d\n", s[i], row, col);
            if(s[i] == 'R') {
                str[row][col] = '/';
                --row;
                ++col;
            }
            else if (s[i] == 'C') {
                str[row][col] = '_';
                ++col;
            }
            else if (s[i] == 'F') {
                ++row;
                str[row][col] = '\\';
                ++col;
            }
        }
        printf("Case #%d:\n", t+1);
        for (i = 1; i <= mxRow; ++i) {
            printf("|");
            for (j = 0; j <= mxCol; ++j) {
                    putchar(str[i][j]);
            }
            putchar('\n');
        }
        printf("+");
        for (i = 0; i < mxCol + 2; ++i) {
            putchar('-');
        }
        putchar('\n');
    }


    return (0);
}
