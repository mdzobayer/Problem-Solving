class Solution {
public:
    int appendCharacters(string s, string t) {
        int i, sIndex = 0, alphabet, ans = 0;
        queue<int> frontFreq[26];

        for (i = 0; i < s.size(); ++i) {
            alphabet = s[i] - 'a';
            frontFreq[alphabet].push(i);
        }

        for (i = 0; i < t.size(); ++i) {

            alphabet = t[i] - 'a';

            while(!frontFreq[alphabet].empty() && frontFreq[alphabet].front() < sIndex) {
                frontFreq[alphabet].pop();
            }

            if (!frontFreq[alphabet].empty()) {
                sIndex = frontFreq[alphabet].front();
                frontFreq[alphabet].pop();
            }
            else {
                ans += (t.size() - i);
                break;
            }
        }

        return ans;
    }
};