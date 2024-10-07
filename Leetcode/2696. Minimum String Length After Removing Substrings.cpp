class Solution {
public:
    int minLength(string s) {
        
        while(isTrimed(s)) {}

        return s.size();
    }

    bool isTrimed(string & s) {
        bool ans = false;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == 'A' && s[i] == 'B') {
                s.erase(i - 1, 2);
                ans = true;
            }
            else if (s[i - 1] == 'C' && s[i] == 'D') {
                s.erase(i - 1, 2);
                ans = true;
            }
        }

        return ans;
    }
};