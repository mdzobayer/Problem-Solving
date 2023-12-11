class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> frequency;

        int i, ans = arr[0], count = 1;
        for (i = 0; i < arr.size(); ++i) {
            frequency[arr[i]] += 1;
        }

        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            if (it->second > count) {
                count = it->second;
                ans = it->first;
            }
        }

        return ans;
    }
};