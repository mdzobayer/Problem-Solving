class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i, size = nums.size();

        int prefixMin[size];

        prefixMin[0] = nums[0];
        for (i = 1; i < size; ++i) {
            if (prefixMin[i - 1] < nums[i]) {
                prefixMin[i] = prefixMin[i - 1];
            }
            else {
                prefixMin[i] = nums[i];
            }
        }

        bool ans = false;

        stack<int> stk;

        for (i = size - 1; i > 0; --i) {
            while(!stk.empty() && stk.top() < nums[i]) {
                if (prefixMin[i - 1] < stk.top()) {
                    ans = true;
                    break;
                }
                stk.pop();
            }

            if (ans) break;
            
            stk.push(nums[i]);
        }

        return ans;
    }
};