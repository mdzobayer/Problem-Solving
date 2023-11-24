class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());

        int i, ans = 0, index = piles.size() / 3;
        for (i = 1; i < (index + index); i += 2) {
            ans += piles[i];
        }

        return ans;
    }
};