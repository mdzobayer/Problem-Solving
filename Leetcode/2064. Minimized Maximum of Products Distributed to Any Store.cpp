class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 0, right = *max_element(quantities.begin(), quantities.end());

        while(left < right) {
            int middle = (left + right) / 2;
            if (canDistribute(middle, quantities, n)) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

    bool canDistribute(int x, vector<int> & quantities, int n) {
        int j = 0, remaining = quantities[j];

        for (int i = 0; i < n; ++i) {
            if (remaining <= x) {
                ++j;
                if (j == quantities.size()) {
                    return true;
                }
                else {
                    remaining = quantities[j];
                }
            }
            else {
                remaining -= x;
            }
        }

        return false;
    }
};