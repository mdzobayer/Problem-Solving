class Solution {
public:
    int minimumDeletions(string s) {
        int i, j, n = s.size(), ans = n;

        vector<int> beforeB(n + 1, 0), afterA(n + 1, 0);
        
        for (i = 0, j = n - 1; i < n; ++i, --j) {
            if (s[i] == 'b') beforeB[i] = 1;
            if (i > 0) beforeB[i] += beforeB[i - 1];

            if (s[j] == 'a') afterA[j] = 1;
            if (j < n - 1) afterA[j] += afterA[j + 1];
        }

        for (i = 0; i < n; ++i) {
            ans = min(ans, (beforeB[i] + afterA[i]) - 1);
        }

        return ans;
    }
};