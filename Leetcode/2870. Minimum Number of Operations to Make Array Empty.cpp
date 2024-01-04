class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i, ans = 0, temp, len = nums.size();
        vector<int> counts(1000001, 0);

        for (i = 0; i < len; ++i) {
            counts[nums[i]] += 1;
        }

        for (i = 0; i < 1000001; ++i) {
            if (counts[i] == 0) continue;

            if (counts[i] % 3 == 0) {
                ans += counts[i] / 3;
                counts[i] %= 3;
            }
            else if (counts[i] > 3 && counts[i] % 3 == 1) {
                temp = counts[i] / 3;
                ans += temp - 1;
                counts[i] -= (temp - 1) * 3;
            }
            else if (counts[i] > 3 && counts[i] % 3 == 2) {
                temp = counts[i] / 3;
                ans += temp;
                counts[i] -= (temp) * 3;
            }
            
            if (counts[i] % 2 == 0) {
                ans += counts[i] / 2;
                counts[i] %= 2;
            }

            if (counts[i] > 0) {
                ans = -1;
                break;
            }
        }

        return ans;
    }
};