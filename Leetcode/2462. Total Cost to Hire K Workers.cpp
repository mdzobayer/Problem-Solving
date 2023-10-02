class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<int, vector<int>, greater<int>> left, right;
        int i, j, a;
        long long int ans = 0;

        for (i = 0; i < candidates; ++i) {
            left.push(costs[i]);
        }

        for (j = costs.size() - 1, a = 0; a < candidates && i <= j; --j, a++) {
            right.push(costs[j]);
        }

        a = 0;
        while(a < k) {
            ++ a;

            if (!left.empty() && !right.empty()) {
                if (left.top() <= right.top()) {
                    ans += left.top();
                    left.pop();

                    if (i < costs.size() && i <= j) {
                        left.push(costs[i]);
                        ++i;
                    }
                }
                else {
                    ans += right.top();
                    right.pop();

                    if (j >= 0 && i <= j) {
                        right.push(costs[j]);
                        --j;
                    }
                }
            }
            else if (!left.empty()) {
                ans += left.top();
                left.pop();

                if (i < costs.size() && i <= j) {
                    left.push(costs[i]);
                    ++i;
                }
            }
            else {
                ans += right.top();
                right.pop();

                if (j >= 0 && i <= j) {
                    right.push(costs[j]);
                    --j;
                }
            }
        }

        return ans;
    }
};