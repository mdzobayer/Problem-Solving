class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int,int>>> pq;
        int i, n = nums.size();

        for (i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }

        while(k--) {
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            pq.push({value * multiplier, index});
        }

        vector<int> ans(n);

        while(!pq.empty()) {
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            ans[index] = value;

        }

        return ans;
    }
};