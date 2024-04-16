class Solution {
public:
    bool canPermutePalindrome(string s) {
        int i, odd = 0;
        vector<int> alphaCounts(26, 0);

        for (i = 0; i < s.size(); ++i) {
            ++ alphaCounts[s[i] - 'a'];
        }

        for (i = 0; i < 26; ++i) {
            if (alphaCounts[i] > 0 && alphaCounts[i] % 2 != 0) {
                ++odd;
            }
        }

        return odd > 1 ? false : true;
    }
};