class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<string> vt;
        int i, j, k;
        string str = "";

        for (i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                vt.push_back(str);
                str = "";
            }
            else {
                str += s[i];
            }
        }

        vt.push_back(str);
        str = "";

        k = 0;
        for (i = vt.size() - 1; i >= 0; --i) {
            if (i < vt.size() - 1) {
                s[k] = ' ';
                ++k;
            }
            for (j = 0; j < vt[i].size(); ++j, ++k) {
                s[k] = vt[i][j];
            }
        }
    }
};