class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> counts(1000+2, 0);
        int i, ans = 0;

        for (i = 0; i < arr.size(); ++i) {
            counts[arr[i]] += 1;
        }

        for (i = 0; i < 1000; ++i) {
            if (counts[i] > 0 && counts[i + 1] > 0) {
                ans += counts[i];
            }
        }

        return ans;
    }
};