class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int i, maxElement = *max_element(nums.begin(), nums.end());

        vector<int> lastPrime(maxElement + 1, 0);
        for (i = 2; i <= maxElement; ++i) {
            if (isPrime(i)) {
                lastPrime[i] = i;
            }
            else lastPrime[i] = lastPrime[i - 1];
        }

        for (i = 0; i < nums.size(); ++i) {
            int bound;
            
            if (i == 0) bound = nums[0];
            else bound = nums[i] - nums[i - 1];

            if (bound <= 0) return false;

            int largestPrime = lastPrime[bound - 1];
            nums[i] = nums[i] - largestPrime;
        }

        return true;
    }

    bool isPrime(int x) {
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0) return false;
        }

        return true;
    }
};