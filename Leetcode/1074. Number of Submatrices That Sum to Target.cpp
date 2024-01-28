class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), column = matrix[0].size();
        int i, j, r1, r2, col, ans = 0, sum;

        vector<int> vRow(column + 1, 0);
        vector<vector<int>> prefixSum;

        for (i = 0; i < row + 1; ++i) {
            prefixSum.push_back(vRow);
        }

        for (i = 1; i < row + 1; ++i) {
            for (j = 1; j < column + 1; ++j) {
                prefixSum[i][j] = (prefixSum[i - 1][j] + prefixSum[i][j - 1]) - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        unordered_map<int, int> hashMap;

        for (r1 = 1; r1 < row + 1; ++r1) {
            for (r2 = r1; r2 < row + 1; ++r2) {
                hashMap.clear();
                hashMap.insert({0, 1});

                for (col = 1; col < column + 1; ++col) {

                    sum = prefixSum[r2][col] - prefixSum[r1 - 1][col];
                    if (hashMap.find(sum - target) != hashMap.end()) {
                        ans += hashMap[sum - target];

                        
                    }
                    
                    hashMap[sum] += 1;
                    
                }
            }
        }

        return ans;
    }
};