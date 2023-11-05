class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> counts;
        int i, n = nums.size();

        for (i = 0; i < n; ++i) {
            counts[nums[i]] += 1;
        }
        int ans;
        for (map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            if (it->second == 1) {
                ans = it->first;
                break;
            } 
        }

        return ans;
    }
};