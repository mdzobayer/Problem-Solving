class Solution {
public:
    int kthGrammar(int n, int k) {
        return dfs(n, k, 0);
    }

    int dfs(int n, int k, int rootValue) {
        if (n == 1) return rootValue;

        int nodesInRow = pow(2, n - 1);

        if ((nodesInRow / 2) < k) {
            int newRoot = (rootValue == 0) ? 1 : 0;
            return dfs(n - 1, k - (nodesInRow / 2), newRoot);
        }
        else {
            int newRoot = (rootValue == 0) ? 0 : 1;
            return dfs(n - 1, k, newRoot);
        }
    }

};