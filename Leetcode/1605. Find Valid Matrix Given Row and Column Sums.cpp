class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i, j, m = rowSum.size(), n = colSum.size();
        vector< vector<int> > ansMatrix(m, vector<int>(n, 0));

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                ansMatrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ansMatrix[i][j];
                colSum[j] -= ansMatrix[i][j];
            }
        }

        return ansMatrix;
    }
};