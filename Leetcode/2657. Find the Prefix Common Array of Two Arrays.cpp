class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> countA, countB;
        int i, n = A.size();
        vector<int> ans(n, 0);

        for (i = 0; i < n; ++i) {
            ++countA[A[i]];
            ++countB[B[i]];

            for (auto it = countA.begin(); it != countA.end(); ++it) {
                if (countB.find(it->first) != countB.end()) {
                    ans[i] += min(it->second, countB[it->first]);
                }
            }
        }

        return ans;
    }
};