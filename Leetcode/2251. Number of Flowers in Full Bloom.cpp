class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> startIndex, endIndex, ans;
        int i;

        for (i = 0; i < flowers.size(); ++i) {
            startIndex.push_back(flowers[i][0]);
            endIndex.push_back(flowers[i][1]);
        }

        sort(startIndex.begin(), startIndex.end());
        sort(endIndex.begin(), endIndex.end());

        for (i = 0; i < people.size(); ++i) {
            auto it1 = upper_bound(startIndex.begin(), startIndex.end(), people[i]);
            auto it2 = lower_bound(endIndex.begin(), endIndex.end(), people[i]);
            int beforeStarted = it1 - startIndex.begin();
            int beforeEnded = it2 - endIndex.begin();

            ans.push_back(beforeStarted - beforeEnded);
        }

        return ans;
    }
};