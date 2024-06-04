class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            ++ freq[c];
        }

        int ans = 0;
        bool hasOdd = false;

        for (auto elem : freq) {
            if (elem.second % 2 == 0) {
                ans += elem.second;
            }
            else {
                ans += elem.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) ans += 1;

        return ans;
    }
};