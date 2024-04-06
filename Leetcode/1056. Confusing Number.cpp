class Solution {
public:
    bool confusingNumber(int n) {
        int digit, original = n, inverseRevert = 0;

        while(n > 0) {
            digit = invertMap(n % 10);
            if (digit == -1) return false;

            inverseRevert *= 10;
            inverseRevert += digit;

            n /= 10;
        }

        return original != inverseRevert;
    }

    int invertMap(int digit) {
        int ans;
        switch(digit) {
            case 0:
                ans = 0;
                break;
            case 1:
                ans = 1;
                break;
            case 6:
                ans = 9;
                break;
            case 8:
                ans = 8;
                break;
            case 9:
                ans = 6;
                break;
            default:
                ans = -1;
        }

        return ans;
    }
};