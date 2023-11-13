class Solution {
public:
    string sortVowels(string s) {
        string ans = "";
        vector<int> vowels;
        int i, j;

        for (i = 0; i < s.size(); ++i) {
            if (!isVowel(s[i])) {
                ans += s[i];
            }
            else {
                vowels.push_back((int)s[i]);
                ans += '_';
            }
        }

        sort(vowels.begin(), vowels.end());
        //next_permutation(vowels.begin(), vowels.end());

        for (i = 0, j = 0; i < ans.size(); ++i) {
            if (ans[i] == '_') {
                ans[i] = (char)vowels[j];
                ++j;
            }
        }

        return ans;
    }

    bool isVowel(const char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }
};