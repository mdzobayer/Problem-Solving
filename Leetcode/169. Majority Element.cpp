class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> counts;
        int majorityCount = nums.size() / 2;
        int element;
        for (int i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;

            if (counts[nums[i]] > majorityCount) {
                element = nums[i];
                break;
            } 
        }

        return element;
    }
};