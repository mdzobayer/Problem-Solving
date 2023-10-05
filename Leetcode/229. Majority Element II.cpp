class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> counts;

        for (int i = 0; i < nums.size(); ++i) {
            //if (counts.find(nums))
            counts[nums[i]] += 1;
        }

        int minLimit = nums.size() / 3;
        vector<int> vt;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (it->second > minLimit) {
                vt.push_back(it->first);
            }
        }

        return vt;
    }
};