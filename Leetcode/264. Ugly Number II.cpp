class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        long long i, currentUgly = 1;
        set<long long> uglyNumberSet;
        uglyNumberSet.insert(currentUgly);

        for (i = 0; i < n; ++i) {
            currentUgly = *uglyNumberSet.begin();
            uglyNumberSet.erase(currentUgly);

            for (int factor : factors) {
                uglyNumberSet.insert(currentUgly * factor);
            }
        }

        return static_cast<int>(currentUgly);
    }
};