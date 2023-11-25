class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        this->n = n;

        solve(1, k, combination);

        return ans;
    }

    void solve(int start, int k, vector<int>& combination) {
        if (k == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = start; i <= n; ++i) {
            combination.push_back(i);
            solve(i + 1, k - 1, combination);
            combination.pop_back();
        }
    }
};