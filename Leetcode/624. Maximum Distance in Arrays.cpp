class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int i, j, minElement, ans = INT_MIN;
        int n = arrays.size();

        priority_queue<pair<int,int>> pq;

        for (i = 0; i < n; ++i) {
            pq.push(make_pair(arrays[i].back(), i));
        }

        pair<int,int> aPair, temp;

        for (i = 0; i < n; ++i) {
            minElement = arrays[i].front();

            aPair = pq.top();
            if (aPair.second == i) {
                pq.pop();
                temp = pq.top();

                ans = max(ans, temp.first - minElement);

                pq.push(aPair);
                continue;
            }

            ans = max(ans, aPair.first - minElement);
        }

        return ans;
    }
};