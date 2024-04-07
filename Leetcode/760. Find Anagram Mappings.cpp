class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> hashTable;
        int i;

        for (i = 0; i < nums2.size(); ++i) {
            hashTable[nums2[i]] = i;
        }

        for (i = 0; i < nums1.size(); ++i) {
            ans.push_back(hashTable[nums1[i]]);
        }

        return ans;
    }
};