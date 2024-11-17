class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int i, n = nums.size();
        int shortestSubarrayLen = INT_MAX;
        long long cumulativeSum = 0;

        priority_queue< pair<long long, int>, vector<  pair<long long, int> >, greater<> > prefixSumHeap;

        for (i = 0; i < n; ++i) {
            cumulativeSum += nums[i];

            if (cumulativeSum >= k) {
                shortestSubarrayLen = min(shortestSubarrayLen, i + 1);
            }

            while(!prefixSumHeap.empty() && cumulativeSum - prefixSumHeap.top().first >= k) {
                shortestSubarrayLen = min(shortestSubarrayLen, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }

            prefixSumHeap.push({cumulativeSum, i});
        }

        return shortestSubarrayLen == INT_MAX ? -1 : shortestSubarrayLen;
    }
};