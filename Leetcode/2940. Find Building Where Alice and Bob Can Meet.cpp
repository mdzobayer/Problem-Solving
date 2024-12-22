class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int i, q = queries.size();
        vector< pair<int,int> > monoStack;
        vector<int> result(q, -1);
        vector< vector< pair<int,int> > > newQueries(heights.size());

        for (i = 0; i < q; ++i) {
            int a = queries[i][0], b = queries[i][1];

            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b) {
                result[i] = b;
            }
            else {
                newQueries[b].push_back({heights[a], i});
            }
        }

        for (i = heights.size() - 1; i >= 0; --i) {
            int monoStackSize = monoStack.size();
            for (auto & [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0) {
                    result[b] = monoStack[position].second;
                }
            }

            while(!monoStack.empty() && monoStack.back().first <= heights[i]) {
                monoStack.pop_back();
            }
            monoStack.push_back({heights[i], i});
        }

        return result;
    }

    int search(int height, vector< pair<int,int> >& monoStack) {
        int left = 0, right = monoStack.size() - 1, ans = -1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};