class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int i, j, x, y, n = nums.size();
        vector<pair<int,int>> list;

        for (i = 0; i < n; ++i) {
            string digits = to_string(nums[i]);
            x = 0;
            for (j = 0; j < digits.size(); ++j) {
                x *= 10;
                x += mapping[digits[j] - '0'];
            }

            list.push_back(make_pair(x, i));
        }

        sort(list.begin(), list.end());

        vector<int> ans;
        for (i = 0; i < n; ++i) {
            x = list[i].second;
            ans.push_back(nums[x]);
        }

        return ans;
    }
};