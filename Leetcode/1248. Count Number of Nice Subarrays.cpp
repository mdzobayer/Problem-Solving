class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i, lastPopped = -1, gap, ans = 0, n = nums.size();
        queue<int> oddIndices;

        for (i = 0; i < n; ++i) {
            
            if (nums[i] & 1) {
                oddIndices.push(i);
            }

            if (oddIndices.size() > k) {
                lastPopped = oddIndices.front();
                oddIndices.pop();
            }

            if (oddIndices.size() == k) {
                gap = oddIndices.front() - lastPopped;
                ans += gap;
            }
        }

        return ans;
    }
};