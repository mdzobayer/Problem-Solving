class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int i, ans = 0, left = 1, right = position.back(), mid;

        while(left <= right) {
            mid = (left + right) / 2;

            if (distributePossible(position, m, mid)) {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return ans;
    }

    bool distributePossible(vector<int>& position, int m, int mid) {
        int i, count = 1, last = 0, gap;

        for (i = 1; i < position.size() && count < m; ++i) {
            gap = position[i] - position[last];
            if (gap >= mid) {
                ++ count;
                last = i;
            }
        }

        return (count == m); 
    }
};