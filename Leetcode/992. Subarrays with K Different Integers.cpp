class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }

    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        int left, right, cnt, ans = 0, n = nums.size();

        for (left = 0, right = 0; right < n; ++ right) {
            ++ hashTable[nums[right]];

            while(hashTable.size() > k) {
                cnt = -- hashTable[nums[left]];
                if (cnt == 0) {
                    hashTable.erase(nums[left]);
                }
                ++ left;
            }


            ans += (right - left + 1);
            
        }

        return ans;
    }
};