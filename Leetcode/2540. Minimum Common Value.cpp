class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i, ans = -1;
        for (int i = 0; i < nums1.size(); ++i) {
            if (binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                ans = nums1[i];
                break;
            }
        }

        return ans;
    }
};