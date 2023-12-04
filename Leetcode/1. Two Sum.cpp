class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indices;

        int i;

        for (i = 0; i < nums.size(); ++i) {
            indices.push_back(make_pair(nums[i], i));
        }

        sort(indices.begin(), indices.end());

        int left = 0, right = nums.size() - 1;
        vector<int> ans;

        while(left < right) {
            if (indices[right].first + indices[left].first < target) {
                ++left;
            }
            else if (indices[right].first + indices[left].first > target) {
                --right;
            }
            else {
                ans.push_back(indices[left].second);
                ans.push_back(indices[right].second);
                break;
            }
        }

        return ans;
    }
};