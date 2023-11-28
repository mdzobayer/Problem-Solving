class Solution {
public:
    int numberOfWays(string corridor) {
        long long int i, j = 0, seat = 0, ans = 1;
        int mod = 1e9 + 7;

        for (i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S') {
                ++seat;

                if (seat > 2 && seat % 2 == 1) {
                    ans *= (i - j);
                    ans %= mod;
                }
                j = i;
            }
        }

        return (seat > 0 && seat % 2 == 0) ? ans : 0;
    }
};