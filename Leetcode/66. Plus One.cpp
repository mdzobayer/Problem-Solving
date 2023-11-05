class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int i, digit, carry = 1, n = digits.size();

        for (i = n - 1; i >= 0; --i) {
            digit = digits[i] + carry;
            if (digit > 9) {
                carry = 1;
            }
            else carry = 0;

            digit %= 10;

            ans.push_back(digit);
        }

        if (carry > 0) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};