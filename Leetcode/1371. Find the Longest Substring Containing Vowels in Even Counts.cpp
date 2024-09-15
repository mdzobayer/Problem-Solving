class Solution {
public:
    int findTheLongestSubstring(string s) {
        int i, prefixXOR = 0, charMap[26] = {0};
        charMap['a' - 'a'] = 1;
        charMap['e' - 'a'] = 2;
        charMap['i' - 'a'] = 4;
        charMap['o' - 'a'] = 8;
        charMap['u' - 'a'] = 16;
        
        vector<int> mp(32, -1);
        int longSubstring = 0;

        for (i = 0; i < s.size(); ++i) {
            prefixXOR ^= charMap[s[i] - 'a'];
            if (mp[prefixXOR] == -1 && prefixXOR != 0) {
                mp[prefixXOR] = i;
            }

            longSubstring = max(longSubstring, i - mp[prefixXOR]);
        }

        return longSubstring;
    }

};