class Solution {
public:
    int integerBreak(int n) {
        
        int i, ans = 1, squareRoot;

        if (n == 2) return 1;
        else if (n == 3) return 2;

        int x = n / 3;
        
        int sum = x * 3;
        int remain = n - sum;
        if (remain == 1) {
            ans = pow(3, x - 1);
            ans *= 4;
        }
        else if (remain == 2) {
            ans = pow(3, x);
            ans *= 2;
        }
        else {
            ans = pow(3, x);
        }

        return ans;
    }

};