class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t) return false;

        int sSize = s.size(), tSize = t.size();

        if (sSize > tSize) return isOneEditDistance(t, s);

        if (tSize - sSize > 1) return false;

        int i = 0, j = 0, cost = 0;

        for (i = 0; i < sSize; ++i) {
            if (s[i] != t[i]) {
                if (sSize == tSize) {
                    // Replace
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else {
                    // Delete
                    return s.substr(i) == t.substr(i + 1);
                } 
            }
        }

        return sSize + 1 == tSize;
    }

};