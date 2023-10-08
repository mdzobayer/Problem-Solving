class Solution {
    int dp[505][505];
    bool isVisited[505][505];
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        memset(isVisited, false, sizeof(isVisited));

        return solve(0, 0, nums1, nums2);
    }

    int solve(int a, int b, vector<int>& nums1, vector<int>& nums2) {
        if (a >= nums1.size() || b >= nums2.size()) return (0);

        if (isVisited[a][b]) return dp[a][b];

        int ans = nums1[a] * nums2[b];
        
        if (a + 1 < nums1.size() && b + 1 < nums2.size())
            ans = max(ans, ans + solve(a + 1, b + 1, nums1, nums2));

        if (b + 1 < nums2.size())
            ans = max(ans, solve(a, b + 1, nums1, nums2));

        if (a + 1 < nums1.size())
            ans = max(ans, solve(a + 1, b, nums1, nums2));

        isVisited[a][b] = true;

        return dp[a][b] = ans;
    }
};