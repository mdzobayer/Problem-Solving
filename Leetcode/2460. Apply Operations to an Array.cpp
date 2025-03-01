class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int i, j, n = nums.size() - 1;
            int len = nums.size();
    
            for (i = 1; i < len; ++i) {
                if (nums[i] == nums[i - 1]) {
                    nums[i - 1] *= 2;
                    nums[i] = 0;
                }
            }
    
            vector<int> ans(len, 0);
    
            for (i = 0, j = 0; i < len; ++i) {
                if (nums[i] > 0) {
                    ans[j++] = nums[i];
                }
            }
    
            return ans;
        }
    };