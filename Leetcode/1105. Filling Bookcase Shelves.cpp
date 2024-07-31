class Solution {
    int n, shelfWidth;
    vector< vector<int> > dp;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        dp.resize(n, vector<int>(shelfWidth + 1, - 1));
        this->shelfWidth = shelfWidth;

        return solve(0, shelfWidth, 0, books);
    }

    int solve(int index, int widthRemain, int maxHeight, vector<vector<int>>& books) {
        vector<int> currentBook = books[index];

        int maxHeightUpdated = max(maxHeight, currentBook[1]);
        if (index == n - 1) {
            if (widthRemain >= currentBook[0]) {
                return maxHeightUpdated;
            }

            return maxHeight + currentBook[1];
        }

        if (dp[index][widthRemain] != -1) return dp[index][widthRemain];

        dp[index][widthRemain] = maxHeight + solve(index + 1, shelfWidth - currentBook[0], currentBook[1], books);

        if (widthRemain >= currentBook[0]) {
            int secondOption = solve(index + 1, widthRemain - currentBook[0], max(maxHeight, currentBook[1]), books);

            dp[index][widthRemain] = min(dp[index][widthRemain], secondOption);
        }

        return dp[index][widthRemain];
    }
};