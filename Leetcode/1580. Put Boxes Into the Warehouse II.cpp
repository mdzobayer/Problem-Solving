class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater<int>());
        //sort(warehouse.begin(), warehouse.end(), greater<int>());

        int i = 0, j = 0, ans = 0, n = boxes.size(), m = warehouse.size();
        vector<int> leftPossible(m), rightPossible(m), maxPossible(m);

        leftPossible[0] = warehouse[0];
        for (i = 1; i < m; ++i) {
            leftPossible[i] = min(leftPossible[i - 1], warehouse[i]);
        }
        rightPossible[m - 1] = warehouse[m - 1];
        for (i = m - 2; i >= 0; --i) {
            rightPossible[i] = min(rightPossible[i + 1], warehouse[i]);
        }

        for (i = 0; i < m; ++i) {
            maxPossible[i] = min(warehouse[i], max(leftPossible[i], rightPossible[i]));
        }

        sort(maxPossible.begin(), maxPossible.end(), greater<int>());

        i = 0, j = 0;
        while(i < n && j < m) {
            if (boxes[i] <= maxPossible[j]) {
                ++ i;
                ++ j;
                ++ ans;
            }
            else {
                ++ i;
            }
        }

        return ans;
    }
};