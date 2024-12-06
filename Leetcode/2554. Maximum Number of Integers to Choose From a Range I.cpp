class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> hashSet(banned.begin(), banned.end());

        vector<int> availables;

        for (int i = 1; i <= n; ++i) {
            if (hashSet.find(i) == hashSet.end()) {
                availables.push_back(i);
            }
        }

        int ans = 0;
        long long int sum = 0;

        for (int item : availables) {
            if (sum + item > maxSum) {
                break;
            }
            sum += item;
            ++ ans;
        }

        return ans;
    }
};