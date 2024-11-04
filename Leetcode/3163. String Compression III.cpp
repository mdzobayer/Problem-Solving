class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1, i;

        for (i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                ++count;

                if (count > 9) {
                    count = 1;

                    ans.push_back('0' + 9);
                    ans.push_back(word[i - 1]);
                }
            }
            else {
                ans.push_back('0' + count);
                ans.push_back(word[i - 1]);
                count = 1;
            }
        }

        if (count > 0) {
            ans.push_back('0' + count);
            ans.push_back(word[i - 1]);
        }

        return ans;
    }
};