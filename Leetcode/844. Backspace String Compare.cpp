class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string processedS = "", processedT = "";

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (processedS.size() > 0)
                    processedS.pop_back();
            }
            else {
                processedS.push_back(s[i]);
            }
        }

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#') {
                if (processedT.size() > 0)
                    processedT.pop_back();
            }
            else {
                processedT.push_back(t[i]);
            }
        }

        return processedS == processedT;
    }
};