// https://leetcode.com/problems/greatest-common-divisor-traversal/solutions/3573061/c-java-python-slides-explanation-bfs-dfs-union-find-connected-graph/

class Graph {
    int n;
    vector<vector<int>> edges;

    void traverse(int x, vector<bool> & visited) {
        visited[x] = true;
        for (int y : edges[x]) {
            if (!visited[y]) {
                traverse(y, visited);
            }
        }
    }

public:

    Graph(int n = 0) : n(n) {
        edges.resize(n);
    }

    void addEdge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    bool isConnected() {
        vector<bool> visited(n);
        traverse(0, visited);
        return count(visited.begin(), visited.end(), true) == n;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        Graph g(n);
        unordered_map<int, int> seen;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                return false;
            }

            vector<int> primeFactors = getPrimeFactors(nums[i]);
            for (int prime: primeFactors) {
                if (seen.find(prime) != seen.end()) {
                    g.addEdge(i, seen[prime]);
                }
                else {
                    seen[prime] = i;
                }
            }
        }

        return g.isConnected();
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                factors.push_back(i);
                while(x % i == 0) {
                    x /= i;
                }
            }
        }

        if (x != 1) {
            factors.push_back(x);
        }

        return factors;
    }
};