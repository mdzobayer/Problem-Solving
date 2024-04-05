class Solution {
public:
    bool isArmstrong(int n) {
        int digits = digitCount(n);

        int ans = 0, cpy = n;

        while(cpy > 0) {
            ans += pow(cpy % 10, digits);
            cpy /= 10;
        }

        return ans == n;
    }

    int digitCount(int n) {
        int ans = 0;

        while(n > 0) {
            ++ ans;
            n /= 10;
        }

        return ans;
    }
};