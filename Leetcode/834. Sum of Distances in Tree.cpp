class Solution {
    vector< vector<int> > ajlist;
    vector<int> count, ans;
    int n;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        ajlist.resize(n, vector<int>());
        ans.resize(n, 0);
        count.resize(n, 1);

        for (int i = 0; i < edges.size(); ++i) {
            ajlist[edges[i][0]].push_back(edges[i][1]);
            ajlist[edges[i][1]].push_back(edges[i][0]);
        }

        postOrder(0, -1);
        dfs(0, -1);

        return ans;
    }

    void postOrder(int node, int parent) {

        for (int child : ajlist[node]) {
            if (child != parent) {
                postOrder(child, node);

                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs(int node, int parent) {
        for (int child : ajlist[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs(child, node);
            }
        }
    }
};