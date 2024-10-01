class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freqRem;

        for (int item : arr) {
            int rem = (item % k + k) % k;
            ++ freqRem[rem];
        }

        for (int item : arr) {
            int rem = (item % k + k) % k;

            if (rem == 0) {
                if (freqRem[rem] % 2 == 1) return false;
            }
            else if (freqRem[rem] != freqRem[k - rem]) return false;
        }

        return true;
    }
};