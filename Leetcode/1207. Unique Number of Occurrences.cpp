class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i, len = arr.size();
        map<int, int> counts;
        set<int> occurrences;

        for (i = 0; i < len; ++i) {
            counts[arr[i]] += 1;
        }

        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (occurrences.find(it->second) != occurrences.end()) {
                return false;
            }
            occurrences.insert(it->second);
        }

        return true;
    }
};