class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;

        if (n < 2) {
            ans.push_back(0);
            return ans;
        }

        vector< unordered_set<int> > ajlist(n, unordered_set<int>());

        for (vector<int>edge : edges) {
            ajlist[edge[0]].insert(edge[1]);
            ajlist[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        int i, remainingNode = n;
        for (i = 0; i < ajlist.size(); ++i) {
            if (ajlist[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while(remainingNode > 2) {
            remainingNode -= leaves.size();

            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *(ajlist[leaf].begin());
                ajlist[neighbor].erase(leaf);
                if (ajlist[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }

            leaves = newLeaves;
        }

        return leaves;
    }
};