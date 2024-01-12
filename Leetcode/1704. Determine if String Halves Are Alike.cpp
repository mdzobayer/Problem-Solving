
class Solution {
public:
    bool vowelOrConsonant(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U')
            return true;
        else
            return false;
    }

    bool halvesAreAlike(string s) {
        int i, a = 0, b = 0, len = s.size();
        int halve = len / 2;

        for (i = 0; i < len; ++i) {
            if (vowelOrConsonant(s[i])) {
                if (i < halve) {
                    ++ a;
                }
                else {
                    ++ b;
                }
            }
            
        }

        return a == b;
    }
};