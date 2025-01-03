class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int i, n = nums.size();
        vector<long long int> preSum(n, 0);

        for (i = 0; i < n; ++i) {
            preSum[i] = nums[i];
            if(i > 0){
                preSum[i] += preSum[i - 1]; 
            }
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = preSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = preSum[n - 1] - preSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};