class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int ans = num, i, j, n = s.size();

        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (s[i] < s[j]) {
                    swap(s[i],s[j]);

                    num = max(num, stoi(s));

                    // revert
                    swap(s[i], s[j]);
                }
            }
        }

        return num;
    }
};