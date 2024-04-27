class Solution {
public:
    int missingNumber(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        
        int i, gap, minGap = INT_MAX, ans = INT_MAX;

        for (i = 1; i < arr.size(); ++i) {
            gap = arr[i] - arr[i - 1];
            minGap = min(minGap, gap);
        }

        for (i = 1; i < arr.size(); ++i) {
            gap = arr[i] - arr[i - 1];
            if (gap > minGap) {
                ans = arr[i - 1] + minGap;
                break;
            }
        }

        if (ans == INT_MAX) {
            ans = arr[0];
        }

        return ans;
    }
};