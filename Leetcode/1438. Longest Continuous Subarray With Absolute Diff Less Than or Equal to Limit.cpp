class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right, ans = 0, n = nums.size();

        priority_queue< pair<int,int> > maxHeap;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;

        for (right = 0; right < n; ++right) {
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});

            while(maxHeap.top().first - minHeap.top().first > limit) {
                left = min(maxHeap.top().second, minHeap.top().second) + 1;

                while(maxHeap.top().second < left) {
                    maxHeap.pop();
                }

                while(minHeap.top().second < left) {
                    minHeap.pop();
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};