class Solution {
public:
    string largestGoodInteger(string num) {
        map<string, int> goodCount;
        int i, count = 0;

        for (i = 2; i < num.size(); ) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                goodCount[num.substr(i - 2, 3)] += 1;
                i += 3;
            }
            else ++i;
        }

        string ans = "";

        if (goodCount.size() > 0) {
            auto it = goodCount.end();
            --it;
            ans = it->first;
        }

        return ans;
    }
};