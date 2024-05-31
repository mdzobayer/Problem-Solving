class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            int cnt = ++freq[num];
            if (cnt > 1) {
                freq.erase(num);
            }
        }
        vector<int> ans;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second == 1) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};