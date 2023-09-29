class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> vt1, vt2;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) {
                vt2.push_back(nums[i]);
            }
            else vt1.push_back(nums[i]);
        }

        vt1.insert(vt1.end(), vt2.begin(), vt2.end());

        return vt1;
    }
};