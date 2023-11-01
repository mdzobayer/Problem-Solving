class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0; 

        vector<string> ans;
        if (nums.size() == 0) return ans;

        int last = nums.front();

        for (i = 1; i < nums.size(); ++i) {
            if (abs((long long int)nums[i] - nums[i - 1]) > 1) {
                if (nums[i - 1] != last) {
                    ans.push_back(to_string(last) + "->" + to_string(nums[i - 1]));
                }
                else {
                    ans.push_back(to_string(last));
                }
                last = nums[i];
            }
        }

        if (nums[i - 1] != last) {
            ans.push_back(to_string(last) + "->" + to_string(nums[i - 1]));
        }
        else {
            ans.push_back(to_string(last));
        }

        return ans;
    }
};