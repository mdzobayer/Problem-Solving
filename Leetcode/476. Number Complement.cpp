class Solution {
public:
    int findComplement(int num) {
       int bit = 1, ans = num;

       while(num > 0) {
        ans = ans ^ bit;
        bit <<= 1;
        num >>= 1;
       }

        return ans;
    }
};