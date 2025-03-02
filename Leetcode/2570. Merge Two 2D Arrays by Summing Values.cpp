class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int, int> sum;
            for (auto & item : nums1) {
                sum[item[0]] += item[1];
            }
    
            for (auto & item : nums2) {
                sum[item[0]] += item[1];
            }
    
            vector<vector<int>> ans;
            for (auto & it : sum) {
                ans.push_back(vector<int>{it.first, it.second});
            }
    
            sort(ans.begin(), ans.end());
    
            return ans;
        }
    };