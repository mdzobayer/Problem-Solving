class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int positiveCounts[105];
        int negativeCounts[105];

        memset(positiveCounts, 0, sizeof(positiveCounts));
        memset(negativeCounts, 0, sizeof(negativeCounts));

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                positiveCounts[nums[i]] += 1;
            }
            else {
                negativeCounts[nums[i] * -1] += 1;
            }
        }
        vector<int> vt;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                if (positiveCounts[nums[i]] > 0) {
                    vt.push_back(nums[i]);
                    positiveCounts[nums[i]] = 0;
                }
            }
            else {
                if (negativeCounts[nums[i] * -1] > 0) {
                    vt.push_back(nums[i]);
                    negativeCounts[nums[i] * -1] = 0;
                }
            }
        }

        for (int i = 0; i < vt.size(); ++i) {
            nums[i] = vt[i];
        }

        return vt.size();
    }
};