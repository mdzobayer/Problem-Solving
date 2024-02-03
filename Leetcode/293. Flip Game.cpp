class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        string copyStr;
        int i;

        for (i = 1; i < currentState.size(); ++i) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                copyStr = currentState;
                copyStr[i] = '-';
                copyStr[i - 1] = '-';
                ans.push_back(copyStr);
            }
        }

        return ans;
    }
};