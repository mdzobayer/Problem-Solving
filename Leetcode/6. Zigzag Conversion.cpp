class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows;
        string str = "";

        int i, j;
        bool direction = true;
        for (i = 0; i < numRows; ++i) {
            rows.push_back(str);
        }

        i = 0;
        while(i < s.size()) {

            rows[j].push_back(s[i]);

            ++ i;

            if (direction) ++ j;
            else -- j;

            if (j < 0 || j == numRows) {
                if (direction) {
                    direction = false;
                    --j;
                    --j;
                }
                else {
                    direction = true;
                    ++j;
                    ++j;
                }
            }
        }

        string ans = "";
        for (i = 0; i < numRows; ++i) {
            ans += rows[i];
        }

        return ans;
    }
};