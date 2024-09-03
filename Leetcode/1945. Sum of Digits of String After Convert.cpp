class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        int ans;

        // convert
        for (char ch : s) {
            str += to_string(ch + 1 - 'a');
        }
        s = str;
        
        while(k > 0) {

            ans = 0;
            for (char ch : s) {
                ans += (ch - '0');
            }

            -- k;
            s = to_string(ans);
        }

        return ans;
    }
};