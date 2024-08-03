class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int item : target) {
            ++ freq[item];
        }

        for (int item : arr) {
            if (freq.find(item) != freq.end() && freq[item] > 0) {
                -- freq[item];
            }
            else return false;
        }

        return true;
    }
};