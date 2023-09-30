class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i, ans = 0, num;

        priority_queue<int> pq;

        for (i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
        }
        
        while(!pq.empty()) {
            num = pq.top();
            pq.pop();

            if (k == 1) {
                ans = num;
                break;
            }
            --k;
        }

        return ans;
    }
};