class Solution {
public:
    int trailingZeroes(int n) {
        int i, number, ans = 0;

        for (i = 5; i <= n; i += 5) {
            number = i;
            while(number % 5 == 0) {
                ++ ans;
                number /= 5;
            }
        }

        return ans;
    }
};