class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> uniqueSet(nums.begin(), nums.end());

        int ans = 0;

        for (int num : nums) {
            int currentStreak = 0;

            while(uniqueSet.find(num) != uniqueSet.end()) {
                ++ currentStreak;

                if ((long long)num * num > 1e5) break;
                num *= num;
            }

            ans = max(ans, currentStreak);
        }

        return ans < 2 ? -1 : ans;
    }
};