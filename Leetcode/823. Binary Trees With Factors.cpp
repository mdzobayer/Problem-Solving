#define ll long long int
class Solution {
    int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int i, j, k, x, n = arr.size();
        
        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1);
        map<int, int> indexMap;

        for (i = 0; i < n; ++i) {
            indexMap[arr[i]] = i;
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    x = arr[i] / arr[j];
                    if (indexMap.find(x) != indexMap.end()) {
                        k = indexMap[x];

                        dp[i] = ((ll)dp[i] + ((ll)dp[j] * dp[k]) % mod) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (i = 0; i < n; ++i) {
            ans = ((ll)ans + dp[i]) % mod;
        }

        return ans;
    }
};