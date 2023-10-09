class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>::iterator it;
        vector<int> ans;

        if (binary_search(nums.begin(), nums.end(), target)) {
            it = lower_bound(nums.begin(), nums.end(), target);
            ans.push_back(it - nums.begin());
            it = upper_bound(nums.begin(), nums.end(), target);
            ans.push_back(it - nums.begin() - 1);
        }
        else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        

        return ans;
    }
};