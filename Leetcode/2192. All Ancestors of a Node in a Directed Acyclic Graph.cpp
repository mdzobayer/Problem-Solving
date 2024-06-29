class Solution {
    vector< vector<int> > ajlist;
    vector< vector<int> > ancestors;
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ajlist.resize(n, vector<int>());
        ancestors.resize(n, vector<int>());
        int i;

        for (i = 0; i < edges.size(); ++i) {
            ajlist[edges[i][0]].push_back(edges[i][1]);
        }

        for(i = 0; i < n; ++i) {
            findChildDFS(i, i);
        }

        return ancestors;
    }

    void findChildDFS(int ancestor, int currentNode) {
        for (int child : ajlist[currentNode]) {
            if (ancestors[child].empty() || ancestors[child].back() != ancestor) {
                ancestors[child].push_back(ancestor);
                findChildDFS(ancestor, child);
            }
        }
    }
};