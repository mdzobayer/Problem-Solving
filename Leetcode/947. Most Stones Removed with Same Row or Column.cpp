class Solution {

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.union_set(i, j);
                }
            }
        }

        return n - uf.Count();
    }

    class UnionFind {
    private:
        vector<int> parent, rank;
        int count;
    public:
        UnionFind(int size) {
            parent.resize(size, -1);
            rank.resize(size, 1);
            count = size;
        }

        int Count() {return count;}

        int find(int x) {
            if (parent[x] == -1) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        void union_set(int x, int y) {
            int xset = find(x), yset = find(y);

            if (xset == yset) return;
            else if (rank[xset] < rank[yset]) {
                parent[xset] = yset;
            }
            else if (rank[xset] > rank[yset]) {
                parent[yset] = xset;
            }
            else {
                parent[yset] = xset;
                rank[xset] ++;
            }
            -- count;
        }
    };

};