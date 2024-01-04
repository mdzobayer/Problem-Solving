class Solution {
public:
    double myPow(double x, int n) {
        return binaryExpo(x, n);
    }

    double binaryExpo(double x, long long int n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / binaryExpo(x, -n);

        if (n % 2) return x * binaryExpo(x * x, (n - 1) / 2);

        return binaryExpo(x * x, n / 2);
    }
};