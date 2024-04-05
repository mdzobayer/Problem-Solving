class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int i, shiftNeed, dir, n = s.size();
        string finalStr = s;

        for (i = 0; i < shift.size(); ++i) {
            shiftNeed = shift[i][1] % n;
            dir = shift[i][0];

            if (dir == 0) {
                finalStr = finalStr.substr(shiftNeed) + finalStr.substr(0, shiftNeed);
            }
            else {
                finalStr = finalStr.substr(n - shiftNeed) + finalStr.substr(0, n - shiftNeed);
            }
        }

        return finalStr;
    }
};