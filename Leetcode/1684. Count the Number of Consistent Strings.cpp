class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedChars;
        int ans = 0;

        for (char ch : allowed) {
            allowedChars.insert(ch);
        }

        for (string & word : words) {
            bool isValid = true;
            for (char & ch : word) {
                if (allowedChars.find(ch) == allowedChars.end()) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) ++ ans;
        }

        return ans;
    }
};