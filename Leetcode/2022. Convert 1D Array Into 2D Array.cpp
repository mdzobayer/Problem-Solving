class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return vector<vector<int>> {};

        vector< vector<int> > ans(m, vector<int>());

        int row = 0, count = 0;
        for (int item : original) {
            ans[row].push_back(item);
            ++count;
            if (count % n == 0) ++ row;
        }

        return ans;
    }
};