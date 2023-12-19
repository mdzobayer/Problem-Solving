class Solution {
    int m, n;
    int dir[8][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1},
        {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
    };
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();

        int i, j, k, cnt, sum;
        vector<vector<int>> ans;
        vector<int> ansRow(n, 0);
        for (i = 0; i < m; ++i) ans.push_back(ansRow);


        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                cnt = 1;
                sum = img[i][j];
                for (k = 0; k < 8; ++k) {
                    if (isValid(i + dir[k][0], j + dir[k][1])) {
                        ++ cnt;
                        sum += img[i + dir[k][0]][j + dir[k][1]];
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }

        return ans;
    }

    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
};