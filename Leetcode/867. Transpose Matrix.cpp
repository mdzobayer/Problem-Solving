class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int i, j, m = matrix.size(), n = matrix[0].size();

        vector<int> row(m);
        vector<vector<int>> ansMatrix;
        for (i = 0; i < n; ++i) {
            ansMatrix.push_back(row);
        }

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                ansMatrix[j][i] = matrix[i][j];
            }
        }

        return ansMatrix;
    }
};