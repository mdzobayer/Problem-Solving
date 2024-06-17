class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a;
        double b;

        for (a = 0; a * a <= c; ++a) {
            b = sqrt(c - (a * a));
            if (b == (int)b) return true;
        }

        return false;
    }
};