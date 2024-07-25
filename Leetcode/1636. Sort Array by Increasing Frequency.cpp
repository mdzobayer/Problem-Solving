class Solution {
public:
    static bool compare(const pair<int, int> & a, const pair<int, int> & b) {
        if (a.first < b.first) return true;
        else if (a.first > b.first) return false;

        if (a.second > b.second) return true;
        return false; 
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        int i, j, n = nums.size();

        for (i = 0; i < n; ++i) {
            ++ freq[nums[i]];
        }

        vector< pair<int, int> > list;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            list.push_back({it->second, it->first});
        }

        sort(list.begin(), list.end(), compare);

        vector<int> ans;
        for (i = 0; i < list.size(); ++i) {
            for (j = 0; j < list[i].first; ++j) {
                ans.push_back(list[i].second);
            }
        }

        return ans;
    }
};