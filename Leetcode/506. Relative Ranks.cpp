class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int i, n = score.size();
        priority_queue<pair<int, int>> pq;
        vector<string> ans(n);

        for (i = 0; i < n; ++i) {
            pq.push(make_pair(score[i], i));
        }

        i = 0;
        while(!pq.empty()) {
            if (i == 0)
                ans[pq.top().second] = "Gold Medal";
            else if (i == 1)
                ans[pq.top().second] = "Silver Medal";
            else if (i == 2)
                ans[pq.top().second] = "Bronze Medal";
            else
                ans[pq.top().second] = to_string(i + 1);
            
            pq.pop();

            ++i;
        }

        return ans;
    }
};