class Solution {
public:
    int minimumDeletions(string s) {
        int i, n = s.size(), ans = n;

        vector<int> beforeB(n + 1, 0), afterA(n + 1, 0);
        
        for (i = 0; i < n; ++i) {
            if (s[i] == 'b') beforeB[i] = 1;
            if (i > 0) beforeB[i] += beforeB[i - 1];
        }

        for (i = n - 1; i >= 0; --i) {
            if (s[i] == 'a') afterA[i] = 1;
            if (i < n - 1) afterA[i] += afterA[i + 1];
        }

        for (i = 0; i < n; ++i) {
            ans = min(ans, (beforeB[i] + afterA[i]) - 1);
        }

        return ans;
    }
};