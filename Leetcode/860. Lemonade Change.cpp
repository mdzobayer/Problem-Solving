class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans = true;

        int fiveDollar = 0, tenDollar = 0;

        for (int bill : bills) {
            if (bill == 5) {
                ++ fiveDollar;
            }
            else if (bill == 10) {
                ++ tenDollar;
                -- fiveDollar;
                if (fiveDollar < 0) {
                    ans = false;
                    break;
                }
            }
            else {
                bill -= 5;
                if (tenDollar > 0) {
                    -- tenDollar;
                    bill -= 10;
                }

                if ((bill / 5) <= fiveDollar) {
                    fiveDollar -= (bill / 5);
                }
                else {
                    ans = false;
                    break;
                }
            }
        }

        return ans;
    }
};