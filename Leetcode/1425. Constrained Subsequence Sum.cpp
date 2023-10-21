class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int i, ans;
        priority_queue<pair<int, int>> maxHeap;

        maxHeap.push(make_pair(nums[0], 0));
        ans = nums[0];

        for (i = 1; i < nums.size(); ++i) {
            while(maxHeap.top().second < i - k) {
                maxHeap.pop();
            }

            int currentMaximum = max(nums[i], maxHeap.top().first + nums[i]);
            ans = max(ans, currentMaximum);

            maxHeap.push(make_pair(currentMaximum, i));
        }

        return ans;
    }
};