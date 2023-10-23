class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if (n == 1) return true;

        int i = 2;
        long long int powerValue = 4;
        while(powerValue < n) {
            powerValue *= 4;
            ++ i;
        }

        return (powerValue == n);
    }
};