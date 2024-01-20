class Solution {
    int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int i, len = arr.size();

        stack<int> s;
        int ans = 0;

        for (i = 0; i <= len; ++i) {

            while(!s.empty() && (i == len || arr[s.top()] >= arr[i])) {
                int mid = s.top();
                s.pop();

                int left = s.empty() ? -1 : s.top();
                int right = i;

                long count = (mid - left) * (right - mid) % mod;
                ans += (count * arr[mid]) % mod;
                ans %= mod;
            }
            s.push(i);
        }

        return ans;
    }
};