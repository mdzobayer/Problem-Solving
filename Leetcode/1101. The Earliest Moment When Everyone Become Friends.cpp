// UnionFind, DisjoinSet data structure
class UnionFind {
    int rank, parent;
    vector<int> ranks, parents;
public:
    UnionFind(int n) {
        ranks.resize(n + 1);
        parents.resize(n + 1);

        for (int i = 0; i <= n; ++i) {
            ranks[i] = 1;
            parents[i] = i;
        }
    }

    int GetRank(int x) {
        return ranks[GetParent(x)];
    }

    int GetParent(int x) {
        if (x != parents[x]) {
            return parents[x] = GetParent(parents[x]);
        }

        return parents[x];
    }

    void Join(int x, int y) {
        int parentX = GetParent(x);
        int parentY = GetParent(y);

        if (GetRank(x) > GetRank(y)) {
            parents[parentY] = parentX;
            ranks[parentX] += ranks[parentY];
        }
        else {
            parents[parentX] = parentY;
            ranks[parentY] += ranks[parentX];
        }
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind friendsGroup(n);

        sort(logs.begin(), logs.end());

        int i, a, b, time, ans = -1;
        for (int i = 0; i < logs.size(); ++i) {
            time = logs[i][0];
            a = logs[i][1];
            b = logs[i][2];

            if (friendsGroup.GetParent(a) != friendsGroup.GetParent(b)) {
                friendsGroup.Join(a, b);
            }

            if (friendsGroup.GetRank(a) == n) {
                ans = time;
                break;
            }
        }

        return ans;
    }
};