class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNumber, i, indexSoFar = -1;
        
        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] <= target) {
                indexSoFar = i;
            }
        }
        
        if (indexSoFar == -1) return false;
        
        if (matrix[indexSoFar][0] == target) {
            return true;
        }
        
        for (i = 0; i < matrix[indexSoFar].size(); ++i) {
            if (matrix[indexSoFar][i] == target) {
                return true;
            }
        }
        
        return false;
    }
};