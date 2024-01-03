class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int i, j, previousCount = 0, ans = 0, active;

        for (i = 0; i < bank.size(); ++i) {
            active = 0;
            for (j = 0; j < bank[i].size(); ++j) {
                if (bank[i][j] == '1') {
                    ++ active;
                }
            }
            ans += previousCount * active;
            if (active > 0) previousCount = active;
        }

        return ans;
    }
};