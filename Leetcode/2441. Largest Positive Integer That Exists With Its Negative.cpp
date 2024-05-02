class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int i, right = 0, n = nums.size(), ans = -1;
        vector<bool> pos(1001, false), neg(1001, false);

        for (int num : nums) {
            if (num < 0) {
                neg[num * -1] = true;
            }
            else pos[num] = true;

            right = max(right, num);
        }

        while(right > 0) {
            if (pos[right] && neg[right]) {
                ans = right;
                break;
            }
            --right;
        }

        return ans;
    }
};