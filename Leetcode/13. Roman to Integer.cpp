class Solution {
public:
    int romanToInt(string s) {
        int ans = SymbolToVal(s[0]);
        int lastValue = ans;

        for (int i = 1; i < s.size(); ++i) {
            int curr = SymbolToVal(s[i]);

            ans += curr;
            if (curr > lastValue) ans -= lastValue * 2;
            lastValue = curr;
        }

        return ans;
    }

    int SymbolToVal(char ch) {
        int value = 0;
        switch(ch) {
            case 'I' :
            value = 1;
            break;
            case 'V' :
            value = 5;
            break;
            case 'X' :
            value = 10;
            break;
            case 'L' :
            value = 50;
            break;
            case 'C' :
            value = 100;
            break;
            case 'D' :
            value = 500;
            break;
            case 'M' :
            value = 1000;
            break;
        }

        return value;
    }
};