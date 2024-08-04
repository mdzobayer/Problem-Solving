class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        vector<int> sortedArray(set.begin(), set.end());
        reverse(sortedArray.begin(), sortedArray.end());

        if (sortedArray.size() < 3) {
            return sortedArray.front();
        }

        return sortedArray.at(2);
    }
};