class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i, j, maxRow, diagonal, x, y;
        maxRow = nums.size();

        vector<int> ans, emptyVector;
        map<int, vector<int>> diagonalGroups;

        for (i = maxRow - 1; i >= 0; --i) {
            for (j = 0; j < nums[i].size(); ++j) {
                diagonal = i + j;
                if (diagonalGroups.find(diagonal) == diagonalGroups.end()) {
                    diagonalGroups[diagonal] = emptyVector;
                }
                diagonalGroups[diagonal].push_back(nums[i][j]);
            }
        }

        map<int, vector<int>>:: iterator it;
        for(it = diagonalGroups.begin(); it != diagonalGroups.end(); ++it) {
            for (i = 0; i < it->second.size(); ++i) {
                ans.push_back(it->second[i]);
            }
        }

        return ans;
    }
    
    bool isOutSide(int & x, int & y, int & maxRow, int & maxColumn) {
        if (x < 0 || x >= maxRow || y < 0 || y >= maxColumn) return true;

        return false;
    }
};