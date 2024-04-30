class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();

        unordered_map<int, int> freqHashMap;
        freqHashMap[0] = 1;

        int i, odd, bit, mask = 0;
        long result = 0;

        for (i = 0; i < n; ++i) {
            bit = word[i] - 'a';

            mask ^= (1 << bit);

            if (freqHashMap.find(mask) != freqHashMap.end()) {
                result += freqHashMap[mask];
            }

            ++ freqHashMap[mask];

            for (odd = 0; odd < 10; ++ odd) {
                if (freqHashMap.find(mask ^ (1 << odd)) != freqHashMap.end()) {
                    result += freqHashMap[mask ^ (1 << odd)];
                }
            }
        }

        return result;
    }
};