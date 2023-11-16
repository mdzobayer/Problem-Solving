class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int i, value, ans, maxValue = 66000, n = nums.size();

        bool available[maxValue];
        memset(available, false, sizeof(available));
        
        for (i = 0; i < n; ++i) {
            value = binaryToInt(nums[i]);

            available[value] = true;
        }

        for (i = 0; i < maxValue; ++i) {
            if (!available[i]) {
                ans = i;
                break;
            }
        }


        return intToBinary(ans, n);
    }

    int binaryToInt(const string & str) {
        int i, bitValue = 1, ans = 0;

        for (i = str.size() - 1; i >= 0; --i) {
            if (str[i] == '1') ans += bitValue;

            bitValue <<= 1;
        }

        return ans;
    }

    string intToBinary(int n, int len) {
        string ans = "";
        while(n > 0) {
            ans += (char)((n % 2) ? 1 + '0' : '0');
            n >>= 1;
        }

        for (int i = ans.size(); i < len; ++i) {
            ans += '0';
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};