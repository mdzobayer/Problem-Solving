class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int i = 0, n = tokens.size() - 1;
        int maxScore = 0, currentScore = 0;

        while (i <= n) {
            if (tokens[i] <= power) {
                currentScore += 1;
                power -= tokens[i];
                ++i;
                maxScore = max(maxScore, currentScore);
            }
            else if (currentScore > 0) {
                power += tokens[n];
                -- currentScore;
                -- n;
            }
            else break;
        }

        return maxScore;
    }
};