class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        sort(nums1.begin(), nums1.end());

        int i;
        for (int num : nums2) {
            if (binary_search(nums1.begin(), nums1.end(), num)) {
                st.insert(num);
            }
        }

        vector<int> ans(st.begin(), st.end());

        return ans;
    }
};