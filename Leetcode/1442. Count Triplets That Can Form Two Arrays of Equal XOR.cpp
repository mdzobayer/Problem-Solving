class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, ans = 0;
        vector<int> prefixXOR(arr.size() + 1);
        prefixXOR[0] = 0;
        for (i = 0; i < arr.size(); ++i) {
            prefixXOR[i + 1] = arr[i];
            prefixXOR[i + 1] ^= prefixXOR[i];
        }

        for (i = 0; i < prefixXOR.size(); ++i) {
            for (j = i + 1; j < prefixXOR.size(); ++j) {
                if (prefixXOR[i] == prefixXOR[j]) {
                    ans += j - i - 1;
                }
            }
        }

        return ans;
    }
};