class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int left = 1;
        int right = piles.back();
        int mid, ans = right;

        while(left <= right) {
            mid = (left + right) / 2;

            if (isPossible(piles, h, mid)) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(vector<int>& piles, int h, int k) {
        int spendingHours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            spendingHours += (piles[i] / k);
            if ((piles[i] % k) != 0) {
                ++ spendingHours;
            }

            if (spendingHours > h) {
                return false;
            }
        }

        return true;
    }
};