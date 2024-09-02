class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0, ans;

        for (int item : chalk) {
            sum += item;
        }

        k %= sum;

        for (ans = 0; ans < chalk.size(); ++ans) {
            if (chalk[ans] > k) {
                break;
            }
            k -= chalk[ans];
        }

        return ans;
    }
};