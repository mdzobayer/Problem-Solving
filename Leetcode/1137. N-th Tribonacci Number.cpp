class Solution {
public:
    int tribonacci(int n) {
        int i, tribonacciSum[40];

        tribonacciSum[0] = 0;
        tribonacciSum[1] = 1;
        tribonacciSum[2] = 1;

        for (i = 3; i <= n; ++i) {
            tribonacciSum[i] = tribonacciSum[i-1] + tribonacciSum[i - 2] + tribonacciSum[i - 3];
        }

        return tribonacciSum[n];
    }
};