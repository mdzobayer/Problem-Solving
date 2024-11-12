class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        auto comp = [](vector<int>& a, vector<int>& b) { return a[0] < b[0];};

        sort(items.begin(), items.end(), comp);

        vector< vector<int> > queryIndex(queries.size(), vector<int>(2));

        for (int i = 0; i < queries.size(); ++i) {
            queryIndex[i][0] = queries[i];
            queryIndex[i][1] = i;
        }

        sort(queryIndex.begin(), queryIndex.end(), comp);

        vector<int> ans(queries.size());
        int itemIndex = 0, maxBeauty = 0;

        for (int i = 0; i < queries.size(); ++i) {

            int query = queryIndex[i][0];
            int originalIndex = queryIndex[i][1];

            while(itemIndex < items.size() && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                ++ itemIndex;
            }

            ans[originalIndex] = maxBeauty;
        }

        return ans;
    }
};