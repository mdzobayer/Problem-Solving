class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hashTable;
        int left, right, cnt, ans = 0, n = s.size();

        for (left = 0, right = 0; right < n; ++ right) {
            ++ hashTable[s[right]];

            while(hashTable.size() > k) {
                cnt = -- hashTable[s[left]];
                if (cnt == 0) {
                    hashTable.erase(s[left]);
                }
                ++ left;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};