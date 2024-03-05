class Solution {
public:
    int minimumLength(string s) {
        int i, j, ans, count = 1;

        vector<pair<char, int>> sequence;

        for (i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                sequence.push_back(make_pair(s[i - 1], count));
                count = 1;
            }
            else {
                ++ count;
            }
        }

        if (count > 0) {
            sequence.push_back(make_pair(s.back(), count));
        }

        i = 0;
        j = sequence.size() - 1;
        ans = s.size();

        while(i <= j) {
            if (sequence[i].first != sequence[j].first) {
                break;
            }

            if (i != j) {
                ans -= sequence[i].second;
                ans -= sequence[j].second;
            }
            else if(sequence[j].second > 1) {
                ans -= sequence[j].second;
            }
            
            ++ i;
            -- j;
        }

        return ans;
    }
};