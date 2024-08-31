class Solution {
public:
    int pathSum(vector<int>& nums) {
        int sum = 0;

        unordered_map<int, int> hashMap;
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            hashMap[coordinates] = value;
        }

        dfs(nums[0] / 10, 0, sum, hashMap);

        return sum;
    }

    void dfs(int rootCoordinates, int preSum, int& sum, unordered_map<int, int> hashMap) {
        int level = rootCoordinates / 10;
        int position = rootCoordinates % 10;

        int left = (level + 1) * 10 + position * 2 - 1;
        int right = (level + 1) * 10 + position * 2;
        int currSum = preSum + hashMap[rootCoordinates];

        if (!hashMap.count(left) && !hashMap.count(right)) {
            sum += currSum;
            return;
        }

        if (hashMap.count(left)) {
            dfs(left, currSum, sum, hashMap);
        }

        if (hashMap.count(right)) {
            dfs(right, currSum, sum, hashMap);
        }
    }
};