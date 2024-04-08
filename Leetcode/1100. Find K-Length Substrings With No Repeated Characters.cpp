class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        unordered_map<int, int> hashMap;
        int i, cnt, ans = 0;

        for (i = 0; i < k && i < s.size(); ++i) {
            cnt = ++ hashMap[s[i]];
        }
        
        if (k == hashMap.size()) ++ ans;

        for (i = k; i < s.size(); ++i) {
            ++ hashMap[s[i]];
            cnt = -- hashMap[s[i - k]];

            if (cnt == 0) {
                hashMap.erase(s[i - k]);
            }

            if (k == hashMap.size()) ++ ans;
        }

        return ans;
    }
};