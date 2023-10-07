class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> non_duplicate_set;

        for (int i = 0; i < nums.size(); ++i) {
            set<int>::iterator it = non_duplicate_set.find(nums[i]);
            if (it == non_duplicate_set.end()) {
                non_duplicate_set.insert(nums[i]);
            }
            else {
                non_duplicate_set.erase(it);
            }
        }

        return *(non_duplicate_set.begin());
    }
};