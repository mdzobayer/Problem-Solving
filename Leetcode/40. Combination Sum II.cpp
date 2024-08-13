class Solution {
    vector< vector<int> > ans;
    int n;
    set< vector<int> > hashSet;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> items;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, items);

        return ans;
    }

    void solve(int index, int target, vector<int>& candidates, vector<int>& items) {
        if (target == 0) {
            ans.push_back(items);
            return;
        }
        if (target < 0 || index >= n) return;

        for (int i = index; i < n && target >= candidates[i]; ++i) {
            if (i == index || candidates[i] != candidates[i - 1]) {
                items.push_back(candidates[i]);
                solve(i + 1, target - candidates[i], candidates, items);
                items.pop_back();
            }
        }
    }
};