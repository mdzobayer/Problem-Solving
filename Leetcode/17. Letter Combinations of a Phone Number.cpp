class Solution {
    string digitLetters[12] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();

        if (digits.size() > 0) {
            prepareCombination(digits, "", 0);
        }

        return ans;
    }

    void prepareCombination(string & digits, string combination, int digitIndex) {
        if (digitIndex >= digits.size()) {
            ans.push_back(combination);
            return;
        }

        int digit = digits[digitIndex] - '0';

        for (int i = 0; i < digitLetters[digit].size(); ++i) {
            prepareCombination(digits, combination + digitLetters[digit][i], digitIndex + 1);
        }
    }
};