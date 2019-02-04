#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int rows[11][11];
int cols[11][11];
int bucket[11][11];
int gap[11][11];
int num = 0;
int bucketN(int row, int col) {
    return ((row / 3) * 3) + (col / 3);
}

bool isPossible(int grid[11][11], vector<int> vt, int row, int col) {
    if (row > 8 && col > 8) return true;
    if (col > 8 && vt.size() > 0) {
        return false;
    }

    int i, j;
    if (col == 0) {
        vt.clear();
        for ( i = 1; i < 10; ++i) {
            if (rows[row + 1][i] == 0) {
                vt.push_back(i);
            }
        }
    }
    for (j = col; j < 9; ++j) {
        if (grid[row][j] == 0) {
            printf("%d. hello row and col %d %d\n",++num, row, col);
            for (i = 0; i < vt.size(); ++i) {
                if ((bucket[bucketN(row,j) + 1][vt[i]] == 0) && (rows[row + 1][vt[i]] == 0) && (cols[j + 1][vt[i]] == 0)) {
                    grid[row][j] = vt[i];
                    bucket[bucketN(row,j)][vt[i]] = vt[i];
                    rows[row + 1][vt[i]] = vt[i];
                    cols[j + 1][vt[i]] = vt[i];
                    int vElement = vt[i];
                    vt.erase(vt.begin()+i);
                    if (isPossible(grid, vt, row, j + 1)) {

                        return true;
                    }
                    else {
                        bucket[bucketN(row,j)][vt[i]] = 0;
                        rows[row + 1][vt[i]] = 0;
                        cols[j + 1][vt[i]] = 0;
                        grid[row][j] = 0;
                        vt.push_back(vElement);
                        --i;
                    }
                }
            }
        }
    }
    if(isPossible(grid, vt, row + 1, j)) return true;

    return false;
}

int main() {

    vector<int> vt;
    int grid[11][11] = {{0,0,0, 7,2,0, 9,3,6},
                        {2,6,9, 5,0,3, 4,0,0},
                        {7,0,4, 0,6,0, 2,5,0},
                        {1,7,0, 0,9,2, 0,0,3},
                        {0,2,8, 3,0,0, 1,0,5},
                        {0,4,0, 8,0,5, 0,2,7},
                        {0,0,6, 0,7,0, 5,8,2},
                        {8,5,2, 9,0,6, 0,0,0},
                        {4,0,0, 0,0,8, 3,6,0}
                       };
    for (int i = 0; i < 10; ++i) {
        memset(bucket, 0, sizeof(bucket[i]));
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            rows[i+1][grid[i][j]] = grid[i][j];
            cols[i+1][grid[j][i]] = grid[j][i];
            bucket[bucketN(i,j) + 1][grid[i][j]] = grid[i][j];
        }
    }
    //isPossible(grid, 0, 0);
    isPossible(grid, vt, 0, 0);
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return (0);
}
