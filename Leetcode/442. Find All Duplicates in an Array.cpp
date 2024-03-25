class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i, n = nums.size();
        vector<bool> duplicate(n+1, false);
        vector<int> ans;
        
        for (int x : nums) {
            if (duplicate[x]) {
                ans.push_back(x);
            }
            duplicate[x] = true;
        }

        return ans;
    }
};