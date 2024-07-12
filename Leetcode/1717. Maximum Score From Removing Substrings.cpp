class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if (x > y) {
            ans += calculateScore(s, "ab", x);
            ans += calculateScore(s, "ba", y);
        }
        else {
            ans += calculateScore(s, "ba", y);
            ans += calculateScore(s, "ab", x);
        }

        return ans;
    }

    int calculateScore(string & s, string form, int score) {
        string str = "";
        int totalScore = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (str.size() > 0 && str.back() == form.front() && s[i] == form.back()) {
                str.pop_back();
                totalScore += score;
                continue;
            }
            else {
                str.push_back(s[i]);
            }
        }

        s = str;

        return totalScore;
    }
};