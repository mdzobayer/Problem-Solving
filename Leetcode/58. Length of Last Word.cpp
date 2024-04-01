class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string str;
        int lastWordLength = 0;
        while(ss >> str) {
            lastWordLength = str.size();
        }

        return lastWordLength;
    }
};