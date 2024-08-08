class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < prefixSum.size(); ++i) {
            prefixSum[i] = nums[i];
            prefixSum[i] += prefixSum[i - 1];
        }

    }
    
    int sumRange(int left, int right) {
        return prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */