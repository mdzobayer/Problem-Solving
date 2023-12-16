class Solution {
    map<string, bool> visited;
    string beginWord, endWord;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i;

        this->beginWord = beginWord;
        this->endWord = endWord;

        for (i = 0; i < wordList.size(); ++i) {
            visited[wordList[i]] = false;
        }

        queue<pair<string, int>> q;
        pair<string, int> aPair;
        q.push(make_pair(beginWord, 1));

        int ans = 0;

        while(!q.empty()) {
            aPair = q.front();
            q.pop();

            if (aPair.first == endWord) {
                ans = aPair.second;
                break;
            }

            vector<string> seq = generateSequence(aPair.first);

            for (i = 0; i < seq.size(); ++i) {
                if (visited.find(seq[i]) != visited.end()) {
                    if (seq[i] == endWord) {
                        ans = aPair.second + 1;
                        return ans;
                    }
                    if (!visited[seq[i]]) {
                        visited[seq[i]] = true;
                        q.push(make_pair(seq[i], aPair.second + 1));
                    }
                }
            }
        }

        return ans;
    }

    vector<string> generateSequence(string s) {
        vector<string> seq;
        string str = s;
        for (int i = 0; i < s.size(); ++i) {
            str = s;
            for (int j = 'a'; j <= 'z'; ++j) {
                if ((int)s[i] == j) continue;

                str[i] = (char)j;
                seq.push_back(str);
            }
            str[i] = s[i];
        }

        return seq;
    }
};