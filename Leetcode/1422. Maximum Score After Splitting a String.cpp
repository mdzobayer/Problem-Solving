class Solution {
public:
    int maxScore(string s) {
        int i, ans = 0, n = s.size();
        vector<int> leftZeros(n, 0), rightOnes(n, 0);

        leftZeros[0] = (s[0] == '0') ? 1 : 0;
        for (i = 1; i < s.size(); ++i) {
            leftZeros[i] = leftZeros[i - 1];
            if (s[i] == '0') leftZeros[i] += 1;
        }

        rightOnes[n - 1] = (s[n - 1] == '1') ? 1: 0;
        for (i = n - 2; i >= 0; --i) {
            rightOnes[i] = rightOnes[i + 1];
            if (s[i] == '1') rightOnes[i] += 1;
        }

        for (i = 0; i < n - 1; ++i) {
            ans = max(ans, leftZeros[i] + rightOnes[i + 1]);
        }

        return ans;
    }
};