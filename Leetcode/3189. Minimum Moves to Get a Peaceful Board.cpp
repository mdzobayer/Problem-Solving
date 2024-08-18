class Solution {
public:

    static bool compare(const vector<int> &a, const vector<int> & b) {
        return b[1] - a[1] > 0;
    }
    int minMoves(vector<vector<int>>& rooks) {
        int i = 0, minMoves = 0;

        sort(rooks.begin(), rooks.end());

        for (const auto & rook : rooks) {
            minMoves += abs(i - rook[0]);
            ++i;
        }

        sort(rooks.begin(), rooks.end(), compare);
        i = 0;
        for (const auto & rook : rooks) {
            minMoves += abs(i - rook[1]);
            ++i;
        }

        return minMoves;
    }
};