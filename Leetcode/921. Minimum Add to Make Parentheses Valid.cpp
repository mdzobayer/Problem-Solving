class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, minAdds = 0;

        for (char ch : s) {
            if (ch == '(') {
               ++ open;
            }
            else {
                open > 0 ? -- open : ++ minAdds;
            }
        }

        return open + minAdds;
    }
};