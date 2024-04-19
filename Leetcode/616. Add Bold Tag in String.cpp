class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int i, start, n = s.size();
        vector<bool> boldMark(n, false);

        for (string word : words) {
            start = s.find(word);
            while(start != -1) {
                for (i = start; i < start + word.size(); ++i) {
                    boldMark[i] = true;
                }

                start = s.find(word, start + 1);
            }
        }

        string openTag = "<b>", closeTag = "</b>", ans = "";
        bool boldStarted = false;
        for (i = 0; i < n; ++i) {
            if (boldMark[i]) {
                if (!boldStarted) {
                    ans += openTag;
                }
                boldStarted = true;
            }

            if (!boldMark[i] && boldStarted) {
                boldStarted = false;
                ans += closeTag;
            }

            ans += s[i];
        }

        if (boldStarted) {
            boldStarted = false;
            ans += closeTag;
        }

        return ans;
    }
};