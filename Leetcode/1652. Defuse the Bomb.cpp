class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int start = 1, end = k, i, slider = 0, n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans;

        if (k < 0) {
            start = n - abs(k);
            end = n - 1;
        }

        for (i = start; i <= end; ++i) slider += code[i];

        for (i = 0; i < n; ++i) {
            ans[i] = slider;

            slider -= code[start % n];
            slider += code[(end + 1) % n];
            ++ start;
            ++ end;
        }

        return ans;
    }
};