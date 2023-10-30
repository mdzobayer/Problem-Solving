class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tCharCounts;
        map<char, int> sliderCharCounts;

        int i;
        string ans = "";

        for (i = 0; i < t.size(); ++i) {
            tCharCounts[t[i]] += 1;
        }

        // Prepare slider
        for (i = 0; i < s.size() && !isHold(sliderCharCounts, tCharCounts); ++i) {
            sliderCharCounts[s[i]] += 1;
        }

        if (!isHold(sliderCharCounts, tCharCounts)) return ans;

        int j = 0, minIndex = 0, minLen = i, sliderLen = i;

        while(sliderCharCounts[s[j]] > tCharCounts[s[j]]) {
            sliderCharCounts[s[j]] -= 1;
            -- sliderLen;
            ++ j;
        }

        if (sliderLen < minLen) {
            minLen = sliderLen;
            minIndex = j;
        }

        while(i < s.size()) {

            ++ sliderLen;
            sliderCharCounts[s[i]] += 1;

            while(sliderCharCounts[s[j]] > tCharCounts[s[j]]) {
                sliderCharCounts[s[j]] -= 1;
                -- sliderLen;
                ++ j;
            }

            if (sliderLen < minLen) {
                minLen = sliderLen;
                minIndex = j;
            }

            ++ i;
        }

        while(sliderCharCounts[s[j]] > tCharCounts[s[j]]) {
            sliderCharCounts[s[j]] -= 1;
            -- sliderLen;
            ++ j;
        }

        if (sliderLen < minLen) {
            minLen = sliderLen;
            minIndex = j;
        }

        ans = s.substr(minIndex, minLen);

        return ans;
    }

    bool isHold(map<char, int> & sliderCharCounts, map<char, int> & tCharCounts) {
        
        for (auto it = tCharCounts.begin(); it != tCharCounts.end(); ++ it) {
            if (sliderCharCounts.find(it->first) == sliderCharCounts.end()) return false;
            else if (sliderCharCounts[it->first] < it->second) return false;
        }

        return true;
    }
};