class Solution {
    class DSU {
        private: 
            int n;
            vector<int> size;
            vector<int> parent;

        public:
            DSU(int n) {
                this->n = n;

                for (int node = 0; node < n; ++node) {
                    size.push_back(1);
                    parent.push_back(node);
                }
            }

            int find(int node) {
                if (parent[node] == node) {
                    return node;
                }

                return parent[node] = find(parent[node]);
            }

            bool merge(int node1, int node2) {
                node1 = find(node1);
                node2 = find(node2);

                if (node1 == node2) return false;
                else {
                    if (size[node1] > size[node2]) {
                        parent[node2] = node1;
                        size[node1] += size[node2];
                    }
                    else {
                        parent[node1] = node2;
                        size[node2] += size[node1];
                    }
                }

                return true;
            }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for (auto & edge : edges) {
            if (!dsu.merge(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};