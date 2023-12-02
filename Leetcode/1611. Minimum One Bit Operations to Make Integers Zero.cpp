class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int k = 0, current = 1;

        while(current * 2 <= n) {
            current *= 2;
            ++k;
        }

        int twoPowerK = 1 << (k + 1);

        return (twoPowerK - 1) - minimumOneBitOperations(n ^ current);
    }
};