class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> lengths(26, 0), lastIndexes(26, -1);

        int i, ch, maxLen = -1, ans = 0;

        for (i = 0; i < s.size(); ++i) {

            ch = s[i] - 'a';
            if (lastIndexes[ch] > -1) {
                maxLen = max(maxLen, i - lastIndexes[ch] - 1);
            }
            else lastIndexes[ch] = i;
        }

        return maxLen;
    }
};