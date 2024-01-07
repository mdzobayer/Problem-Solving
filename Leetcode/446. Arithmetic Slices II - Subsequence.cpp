#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i, j, n = nums.size();

        ll delta, ans = 0, sum;
        vector< map<ll, int> > counts(n);

        for (i = 1; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                delta = (ll)nums[i] - (ll)nums[j];
                sum = 0;
                if (counts[j].find(delta) != counts[j].end()) {
                    sum = counts[j][delta];
                }

                counts[i][delta] += sum + 1;
                ans += sum;
            }
        }

        return ans;
    }
};