class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(), s.end());

        int i = 0, j, steps = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                ++ i;
            }
            else if (i < s.size() - 1) {
                s[i] = '0';
                int carry = 1;
                j = i + 1;
                while(carry > 0 && j < s.size()) {
                    if (s[j] == '1') {
                        s[j] = '0';
                        carry = 1;
                    }
                    else {
                        s[j] = '1';
                        carry = 0;
                    }
                    ++j;
                }
            } else break;
            ++ steps;
        }

        return steps;
    }
};