class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int i, n = s.size();
        vector<int> diffArray(n, 0);

        for (auto shift : shifts) {
            if (shift[2] == 1) {
                ++diffArray[shift[0]];
                if (shift[1] + 1 < n) {
                    --diffArray[shift[1] + 1];
                }
            }
            else {
                --diffArray[shift[0]];
                if (shift[1] + 1 < n) {
                    ++diffArray[shift[1] + 1];
                }
            }
        }

        string ans(n, ' ');
        int numberOfShifts = 0;

        for (i = 0; i < n; ++i) {
            numberOfShifts = (numberOfShifts + diffArray[i]) % 26;

            if (numberOfShifts < 0) {
                numberOfShifts += 26;
            }

            ans[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return ans;
    }
};