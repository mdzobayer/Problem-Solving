class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int i, n = pref.size();
        vector<int> ans(n);

        ans[0] = pref[0];
        for (i = 1; i < n; ++i) {
            ans[i] = pref[i] ^ pref[i - 1];
        }

        return ans;
    }
};