class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> conn;
        int i, u, v;

        for (i = 0; i < edges.size(); ++i) {
            u = edges[i][0];
            v = edges[i][1];

            ++ conn[u];
            ++ conn[v];
        }

        int ans = conn.begin()->first;
        for(auto it = conn.begin(); it != conn.end(); ++it) {
            if (it->second > conn[ans]) {
                ans = it->first;
            }
        }

        return ans;
    }
};