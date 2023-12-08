class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);
        int i = 0, j = 0, k = 0;

        while(j < m || k < n) {

          if (j < m && k < n) {
            if (nums1[j] <= nums2[k]) {
              ans [i] = nums1[j];
              ++ j;
            }
            else {
              ans [i] = nums2[k];
              ++ k;
            }
          }
          else if (j < m) {
            ans [i] = nums1[j];
            ++ j;
          }
          else {
            ans [i] = nums2[k];
            ++ k;
          }

          ++ i;
        }


        for (i = 0; i < m + n; ++i) {
          nums1[i] = ans[i];
        }
    }
};