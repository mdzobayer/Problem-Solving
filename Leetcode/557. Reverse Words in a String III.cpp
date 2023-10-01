class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string ans = "", word;
        bool isSpace = false;
        while(ss >> word) {
            if (isSpace) {
                ans += " ";
            }
            reverse(word.begin(), word.end());

            ans += word;
            isSpace = true;
        }

        return ans;
    }
};