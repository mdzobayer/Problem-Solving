class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i;

        map<int, vector<int>> indexMap;
        for (i = 0; i < nums.size(); ++i) {
            if (indexMap.find(nums[i]) == indexMap.end()) {
                vector<int> indexes;
                indexes.push_back(i);
                indexMap[nums[i]] = indexes;
            }
            else {
                indexMap[nums[i]].push_back(i);
            }
        }

        vector<int> sameValueIndex;

        for(auto it = indexMap.begin(); it != indexMap.end(); ++it) {            
            if (it->second.size() < 2) continue;

            sameValueIndex = it->second;

            for (i = 1; i < sameValueIndex.size(); ++i) {
                if (abs(sameValueIndex[i] - sameValueIndex[i - 1]) <= k) return true;
            }
        }

        return false;
    }
};