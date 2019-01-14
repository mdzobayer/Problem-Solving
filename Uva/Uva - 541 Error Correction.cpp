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

int main() {
    FastRead

    //fRead("in.txt");

    int matrix[105][105], n, i, j, rowIndex, colIndex;
    int sumRow[105], sumCol[105], rowCount, colCount;

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;
        //memset(matrix, 0, sizeof(matrix));
        memset(sumRow, 0, sizeof(sumRow));
        memset(sumCol, 0, sizeof(sumCol));

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j]);
                sumRow[i] += matrix[i][j];
                sumCol[j] += matrix[i][j];
            }
        }

        rowCount = colCount = 0;
        rowIndex = colIndex = -1;
        for (i = 0; i < n; ++i) {
            if(sumRow[i] & 1) {
                ++rowCount;
                rowIndex = i;
            }
        }
        for (i = 0; i < n; ++i) {
            if (sumCol[i] & 1) {
                colIndex = i;
                ++colCount;
            }
        }
        //printf("r %d c %d\n", rowCount, colCount);
        if (rowCount == 0 && colCount == 0) {
            printf("OK\n");
        }
        else if (rowCount == 1 && colCount == 1)
            printf("Change bit (%d,%d)\n", rowIndex + 1, colIndex + 1);
        else
            printf("Corrupt\n");
    }


    return (0);
}
