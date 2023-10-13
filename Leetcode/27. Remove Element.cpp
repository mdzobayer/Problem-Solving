class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> vt;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                vt.push_back(nums[i]);
        }

        for (int i = 0; i < vt.size(); ++i) {
            nums[i] = vt[i];
        }

        return vt.size();
    }
};