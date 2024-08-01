class Solution {
public:
    int countSeniors(vector<string>& details) {
        int i, ans = 0;

        for (i = 0; i < details.size(); ++i) {
            if (stoi(details[i].substr(11, 2)) > 60) {
                ++ ans;
            }
        }

        return ans;
    }
};