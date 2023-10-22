class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;

        int i, last, activeBlock = 0, maxBlock = 0;

        if (nums.size() == 0) return maxBlock;

        for (i = 0; i < nums.size(); ++i) {
            mp[nums[i]] += 1;
        };

        map<int, int>::iterator it = mp.begin();
        activeBlock = 1;
        maxBlock = 1;
        last = it->first;
        for (++it; it != mp.end(); ++it) {
            int keyValue = it->first;
            int keyCount = it->second;
            if ((keyValue - last) == 1) {
                ++ activeBlock;
                // if (keyCount > 1) {
                //     activeBlock = 1;
                // }
                maxBlock = max(maxBlock, activeBlock);
            }
            else {
                maxBlock = max(maxBlock, activeBlock);
                activeBlock = 1;
            }

            last = keyValue;
        }

        maxBlock = max(maxBlock, activeBlock);

        return maxBlock;
    }
};