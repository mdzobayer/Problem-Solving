class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        if (k > nums.size()) return (0);
        
        int duplicateCounts[100000+5];
        memset(duplicateCounts, 0, sizeof(duplicateCounts));
        
        int i, j, numOfDuplicates = 0;
        long long int totalSum = 0, maxPossibleSum = 0;
        
        for (i = 0; i < k; ++i) {
            totalSum += nums[i];
            duplicateCounts[nums[i]] += 1;
            if (duplicateCounts[nums[i]] > 1) {
                ++numOfDuplicates;
            }
        }
        
        if (numOfDuplicates == 0) {
            maxPossibleSum = max(maxPossibleSum, totalSum);
        }
        
        for (i = k, j = 0; i < nums.size(); ++i, ++j) {
            totalSum += nums[i];
            duplicateCounts[nums[i]] += 1;
            if (duplicateCounts[nums[i]] > 1) {
                ++numOfDuplicates;
            }
            
            totalSum -= nums[j];
            if (duplicateCounts[nums[j]] > 1) {
                --numOfDuplicates;
            }
            duplicateCounts[nums[j]] -= 1;
            
            if (numOfDuplicates == 0) {
                maxPossibleSum = max(maxPossibleSum, totalSum);
            }
            
        }
        
        return maxPossibleSum;
    }
};