class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i, left, right, n = customers.size();

        vector<int> leftCustomer(n + 2, 0), rightCustomer(n + 2, 0);

        for (i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                leftCustomer[i + 1] = customers[i];
            }
            
            leftCustomer[i + 1] += leftCustomer[i];
        }

        for (i = n - 1; i >= 0; --i) {
            if (!grumpy[i]) {
                rightCustomer[i] = customers[i];
            }
            
            rightCustomer[i] += rightCustomer[i + 1];
        }

        int ans = 0, cAns, slider = 0;
        for (left = 0, right = 0; right < n; ++right) {
            slider += customers[right];

            while(right - left >= minutes) {
                slider -= customers[left];
                ++ left;
            }
            cAns = slider + leftCustomer[left] + rightCustomer[right + 1];
            ans = max(ans, cAns);
        }

        return ans;
    }
};