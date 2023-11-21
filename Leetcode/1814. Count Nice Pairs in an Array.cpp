class Solution {
    int mod = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        map<int, int> counts;

        int i, n = nums.size();
        for (i = 0; i < n; ++i) {
            counts[nums[i] - revNums(nums[i])] += 1;
        }
        long long int ans = 0, count;
        for(auto it = counts.begin(); it != counts.end(); ++it) {
            count = it->second - 1;
            //if (count > 1) {
                ans += ((count * count + count) / 2) % mod;
                ans %= mod;
            //}
        }

        return ans;
    }

    int revNums(int x) {
        int rev = 0, mod;

        while(x > 0) {
            mod = x % 10;
            x /= 10;

            rev *= 10;
            rev += mod;
        }

        return rev;
    }
};