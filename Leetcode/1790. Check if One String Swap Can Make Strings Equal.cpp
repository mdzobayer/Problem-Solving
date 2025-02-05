class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i, count = 0, n = s1.size();
        vector<int> s1Frequency(26, 0), s2Frequency(26, 0);

        for (i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++ count;
            }

            ++ s1Frequency[s1[i] - 'a'];
            ++ s2Frequency[s2[i] - 'a'];
        }

        for (i = 0; i < 26; ++i) {
            if (s1Frequency[i] != s2Frequency[i]) {
                return false;
            }
        }

        return (count == 0 || count == 2);
    }
};