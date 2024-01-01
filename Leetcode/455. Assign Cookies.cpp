class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i, j, cnt = 0;
        bool found;

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        for (i = 0, j = 0; i < g.size(); ++i) {
            found = false;
            while(j < s.size()) {
                if (s[j] >= g[i]) {
                    found = true;
                    ++j;
                    ++cnt;
                    break;
                }
                
                ++j;
            }

            if (!found) break;
        }

        return cnt;
    }
};