class Solution {
    int m, n;
public:
    int numSpecial(vector<vector<int>>& mat) {
        int i, j, k, ans = 0;
        m = mat.size();
        n = mat[0].size();

        for (i = 0; i < m; ++i) {
            for (j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    if (isValid(i, j, mat)) ++ ans;
                }
            }
        }

        return ans;
    }

    bool isValid(int x, int y, vector<vector<int>>& mat) {
        int i;
        for (i = x - 1; i >= 0; --i) {
            if (mat[i][y] == 1) return false;
        }

        for (i = x + 1; i < m; ++i) {
            if (mat[i][y] == 1) return false;
        }

        for (i = y - 1; i >= 0; --i) {
            if (mat[x][i] == 1) return false;
        }

        for (i = y + 1; i < n; ++i) {
            if (mat[x][i] == 1) return false;
        }

        return true;
    }
};