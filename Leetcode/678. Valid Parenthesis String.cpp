class Solution {
public:
    bool checkValidString(string s) {
        int i, openB = 0, star = 0;

        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++ openB;
            }
            else if (s[i] == ')') {
                if (openB > 0) {
                    -- openB;
                }
                else if (star > 0) {
                    -- star;
                }
                else return false;
            }
            else {
                ++ star;
            }
        }

        openB = 0;
        star = 0;

        for (i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++ openB;
            }
            else if (s[i] == '(') {
                if (openB > 0) {
                    -- openB;
                }
                else if (star > 0) {
                    -- star;
                }
                else return false;
            }
            else {
                ++ star;
            }
        }

        return true;
    }
};