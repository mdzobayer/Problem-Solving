class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       vector<int> row, counts(201, 0);
       vector<vector<int>> ans; 
       int i, j, maxRow = 0;

       for (i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
            maxRow = max(maxRow, counts[nums[i]]);
       }

       for (i = 0; i < maxRow; ++i) {
           row.clear();
           for (j = 0; j < 201; ++j) {
               if (counts[j] > 0) {
                   row.push_back(j);
                   -- counts[j];
               }
           }
           ans.push_back(row);
       }

       return ans;
    }
};