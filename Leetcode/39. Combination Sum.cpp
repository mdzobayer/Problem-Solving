class Solution {
    int target;
    int n;
    vector<int> candidates;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> elements;
        
        this->candidates = candidates;
        this->n = candidates.size();
        this->target = target;

        findWays(0, 0, elements);

        return ans;
    }

    void findWays(int index, int sum, vector<int>& elements) {
        if (sum == target) {
            ans.push_back(elements);
            return;
        }

        if (index >= n || sum > target) return;

        for (int i = index; i < n; ++i) {
            elements.push_back(candidates[i]);
            findWays(i, sum + candidates[i], elements);
            elements.pop_back();
        }
    }
};