class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashSet;
        int zeroCount = 0;

        for (int item : arr) {
            hashSet.insert(item);
            if (item == 0) ++zeroCount;
        }

        if (zeroCount > 1) return true;

        for (int item : arr) {
            if (item != 0 && hashSet.find(item * 2) != hashSet.end()) {
                return true;
            }
        }

        return false;
    }
};