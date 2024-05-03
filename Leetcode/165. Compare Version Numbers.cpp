class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i, x, y;

        for (i = 0; i < version1.size(); ++i) {
            if (version1[i] == '.') version1[i] = ' ';
        }
        for (i = 0; i < version2.size(); ++i) {
            if (version2[i] == '.') version2[i] = ' ';
        }

        stringstream ss1(version1), ss2(version2);
        vector<int> token1, token2;
        int revision;

        while(ss1 >> revision) {
            token1.push_back(revision);
        }
        while(ss2 >> revision) {
            token2.push_back(revision);
        }

        for (i = 0; i < max(token1.size(), token2.size()); ++i) {
            x = i < token1.size() ? token1[i] : 0;
            y = i < token2.size() ? token2[i] : 0;

            if (x != y) return x < y ? -1 : 1;
        }

        return 0;
    }
};