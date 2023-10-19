class Solution {
public:
    bool isPalindrome(string str) {

        string s = "";

        for (int i = 0; i < str.size(); ++i) {
            if (isalpha(str[i])) {
                s.push_back(tolower(str[i]));
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                s.push_back(str[i]);
            }
        }

        int left = 0, right = s.size() - 1;
        bool isPalin = true;
        while(left < right) {
            if (s[left] != s[right]) {
                isPalin = false;
                break;
            }

            ++left;
            --right;
        }

        return isPalin;
    }
};