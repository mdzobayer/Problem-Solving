class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        for (int num : nums1) {
            ++ freq[num];
        }
        vector<int> ans;
        for (int num : nums2) {
            if (freq.find(num) != freq.end() && freq[num] > 0) {
                -- freq[num];
                ans.push_back(num);
            }
        }

        return ans;
    }
};