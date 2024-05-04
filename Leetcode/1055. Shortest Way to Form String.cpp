class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> available(26, false);

        for (char ch : source) {
            available[ch - 'a'] = true;
        }

        for (char ch : target) {
            if (!available[ch - 'a']) return -1;
        }

        string concatenated = source;
        int ans = 1;
        while(!isSubsequence(target, concatenated)) {
            ++ ans;
            concatenated += source;
        }
        
        return ans;
    }

    bool isSubsequence(string & target, string & subseq) {
        int i = 0, j = 0;

        while(i < target.size() && j < subseq.size()) {
            if (target[i] == subseq[j]) {
                ++i;
            }
            ++j;
        }

        return i == target.size();
    }
};