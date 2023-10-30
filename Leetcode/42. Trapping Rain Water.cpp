class Solution {
public:
    int trap(vector<int>& height) {
        int i, n = height.size(), columnWater, ans = 0;

        vector<int> leftMax(n, 0), rightMax(n, 0);

        leftMax[0] = height.front();
        for (i = 1; i < n; ++i) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[n - 1] = height.back();
        for (i = n - 2; i >= 0; --i) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        for (i = 1; i < n - 1; ++i) {
            columnWater = min(leftMax[i - 1], rightMax[i + 1]) - height[i];
            if (columnWater > 0) {
                ans += columnWater;
            }
        }

        return ans;
    }
};