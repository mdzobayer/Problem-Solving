class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int mid, n = sweetness.size(), left = sweetness.front(), right = 0;
        ++ k;

        for (int s : sweetness) {
            left = min(left, s);
            right += s;
        }

        right /= k;

        while(left < right) {
            mid = (left + right + 1) / 2;

            int sum = 0, completed = 0;

            for (int s : sweetness) {
                sum += s;

                if (sum >= mid) {
                    ++ completed;
                    sum = 0;
                }
            }

            if (completed >= k) {
                left = mid;
            }
            else right = mid - 1;
        }

        return right;
    }
};