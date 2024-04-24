class UnionFind {
private:
    vector<int> parent, rank;
    int count;
public:
    UnionFind(int size) {
        parent.resize(size, -1);
        rank.resize(size, 0);
        count = 0;
    }

    void addLand(int x) {
        if (parent[x] > -1) return;
        parent[x] = x;
        ++ count;
    }

    bool isLand(int x) {
        if (parent[x] > -1) return true;
        return false;
    }

    int landCount() {return count;}

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
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

class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind dsu(m * n);

        int i, x, y, land, cnt = 0;
        vector<int> ans;

        for (i = 0; i < positions.size(); ++i) {
            x = positions[i][0]; y = positions[i][1];
            land = x * n + y;
            dsu.addLand(land);

           
            for (auto dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                int neighborLand = newX * n + newY;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && dsu.isLand(neighborLand)) {
                    dsu.union_set(land, neighborLand);
                }
            }
                
            ans.push_back(dsu.landCount());

        }

        return ans;
    }
};