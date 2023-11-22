class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words(wordDict.begin(), wordDict.end());

        int i, startIndex, endIndex;
        bool ans = false;
        string subStr;
        vector<bool> visited(s.size() + 1, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            startIndex = q.front();
            q.pop();

            if (startIndex == s.size()) {
                ans = true;
                break;
            }

            for (endIndex = startIndex + 1; endIndex <= s.size(); ++endIndex) {
                subStr = s.substr(startIndex, (endIndex - startIndex));
                if (words.find(subStr) != words.end() && 
                !visited[endIndex]) {
                    q.push(endIndex);
                    visited[endIndex] = true;
                }
            }
        }

        return ans;
    }
};