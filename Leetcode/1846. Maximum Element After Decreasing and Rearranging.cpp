class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int i, ans = 1, n = arr.size();
        arr[0] = 1;
        for (i = 1; i < n; ++i) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            ans = max(ans, arr[i]);
        }

        return ans;
    }
};