class Solution {
public:
    bool isVowel(const char & ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    string removeVowels(string s) {
        string ans = "";

        for (char ch : s) {
            if (!isVowel(ch)) {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};