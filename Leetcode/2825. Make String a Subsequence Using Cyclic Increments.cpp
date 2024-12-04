class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i, j, len1 = str1.size(), len2 = str2.size();

        for (i = 0, j = 0; i < len1 && j < len2; ++i) {
            if (str1[i] == str2[j] || (str1[i] + 1 == str2[j]) || 
            (str1[i] - 25 == str2[j])) {
                ++j;
            }
        }

        return j == len2;
    }
};