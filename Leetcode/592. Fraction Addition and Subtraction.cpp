class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;

        while(i < expression.size()) {
            int currNum = 0;
            int currDenom = 0;

            bool isNegative = false;

            // Negative sign check
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    isNegative = true;
                }

                ++i;
            }

            // Build numerator
            while(isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                ++i;
            }

            if (isNegative) currNum *= -1;

            // skip divisor
            ++i;

            // Build denominator
            while(isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenom = currDenom * 10 + val;
                ++i;
            }

            // add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(findGCD(num, denom));
        
        // reduce fraction
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }

    int findGCD(int a, int b) {
        if (a == 0) return b;

        return findGCD(b % a, a);
    }
};