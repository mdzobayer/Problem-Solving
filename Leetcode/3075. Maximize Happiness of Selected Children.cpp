class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int i, n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long int ans = 0;

        for (i = 0; i < n && i < k; ++i) {
            ans += max(happiness[i] - i, 0);
        }

        return ans;
    }
};