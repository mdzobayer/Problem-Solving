class Solution {
public:
    int totalMoney(int n) {
        int i, day, totalMoney = 0, currentInvest = 0;

        for (i = 1, day = 0; day < n; ++i, ++day) {
            if (i > 7) {
                i = 1;
                ++currentInvest;
            }

            totalMoney += currentInvest + i;
        }

        return totalMoney;
    }
};