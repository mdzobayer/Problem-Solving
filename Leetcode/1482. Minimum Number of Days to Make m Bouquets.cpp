class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i, mid, start = 0, end = 0, n = bloomDay.size();

        for (i = 0; i < n; ++i) {
            end = max(end, bloomDay[i]);
        }

        int ans = -1;
        while(start <= end) {
            mid = (start + end) / 2;

            int poss = possibleBoquet(bloomDay, mid, k);
            if (poss >= m) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }

    int possibleBoquet(vector<int>& bloomDay, int dayUse, int k) {
        int count, i, ans = 0;

        count = 0;
        for (i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= dayUse) {
                ++ count;
            }
            else {
                count = 0;
            }

            if (count == k) {
                ++ ans;
                count = 0;
            }
        }

        return ans;
    }
};