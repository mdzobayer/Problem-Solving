class Solution {
public:
    string kthLuckyNumber(int k) {
        int digits = 0;
        int fewerLuckyCount = 0;
        while(fewerLuckyCount < k) {
            digits ++ ;
            fewerLuckyCount += pow(2, digits);
        }

        int x = k - 1 - (fewerLuckyCount - pow(2, digits));

        string kthLuckyNum;
        for (int i = 0; i < digits; ++i) {
            string digit;
            if (x & 1) {
                digit = '7';
            }
            else digit = '4';

            kthLuckyNum.insert(0, digit);
            x /= 2;
        }

        return kthLuckyNum;
    }
};