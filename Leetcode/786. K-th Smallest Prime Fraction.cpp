class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int i, n = arr.size();

        priority_queue< pair<double, pair<int,int> > > pq;

        for (i = 0; i < n; ++i) {
            pq.push(make_pair(-1.0 * arr[i] / arr[n - 1], make_pair(i, n - 1)));
        }

        while(!pq.empty() && --k > 0) {
            pair<int, int> curr = pq.top().second;
            pq.pop();

            -- curr.second;

            pq.push(make_pair(-1.0 * arr[curr.first] / arr[curr.second], make_pair(curr.first, curr.second)));
        }

        pair<int, int> curr = pq.top().second;

        return {arr[curr.first], arr[curr.second]};
    }
};