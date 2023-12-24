class Solution {
public:
    int minOperations(string s) {
        int i, cost1 = 0, cost2 = 0;
        string final1 = "", final2 = "";
        int n = s.size();

        for (i = 0; i < n; ++i) {
            if (i % 2) {
                final1 += '1';
                final2 += '0';
            }
            else {
                final2 += '1';
                final1 += '0';
            }
        }

        for (i = 0; i < s.size(); ++i) {
            if (s[i] != final1[i]) {
                ++ cost1;
            }

            if (s[i] != final2[i]) {
                ++ cost2;
            }
        }

        return min(cost1, cost2);
    }

};