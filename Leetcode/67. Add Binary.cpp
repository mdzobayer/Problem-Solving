class Solution {
public:
    string addBinary(string a, string b) {
        int minLen = min(a.size(), b.size());
        int i, maxLen = max(a.size(), b.size());

        string str = "";
        for (i = minLen; i < maxLen; ++i) {
            str.push_back('0');
        }

        if (minLen == a.size()) {
            a = str + a;
        }
        else {
            b = str + b;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        char carryBit = '0';

        for (i = 0; i < maxLen; ++i) {
            if (a[i] == '1' && b[i] == '1') {
                ans += carryBit;
                carryBit = '1';
            }
            else if (a[i] == '0' && b[i] == '0') {
                ans += carryBit;
                carryBit = '0';
            }
            else {
                if (carryBit == '1') {
                    ans += '0';
                }
                else {
                    ans += '1';
                    carryBit = '0';
                }
            }
        }
        
        if (carryBit == '1') ans += carryBit;

        reverse(ans.begin(), ans.end());

        return ans;
    }
};