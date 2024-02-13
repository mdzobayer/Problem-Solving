class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans;
        int i;
        for (i = 0; i < words.size(); ++i) {
            if (isPalin(words[i])) {
                ans = words[i];
                break;
            }
        }

        return ans;
    }

    bool isPalin(const string & s) {
        int low = 0, high = s.size() - 1;

        while(low < high) {
            if (s[low] != s[high]) return false;
            ++ low;
            -- high;
        }

        return true;
    }
};