class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int i, n = names.size();

        vector< pair<int, int> > list(n);
        vector<string> ans;

        for (i = 0; i < n; ++i) {
            list[i] = make_pair(heights[i], i);
        }

        sort(list.begin(), list.end(), greater<pair<int,int>>());

        for (i = 0; i < n; ++i) {
            ans.push_back(names[list[i].second]);
        }

        return ans;
    }
};