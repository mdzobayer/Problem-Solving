class Solution {
    vector<int> nums;
    int high;
public:
    vector<int> sequentialDigits(int low, int high) {
        int i, j;
        this->high = high;

        for (i = 1; i < 10; ++i) {
            generateNumbers(i);
        }

        sort(nums.begin(), nums.end());

        auto start = lower_bound(nums.begin(), nums.end(), low);
        auto end = upper_bound(nums.begin(), nums.end(), high);

        vector<int> ans(start, end);

        return ans;
    }

    void generateNumbers(int n) {
        if (n > high) return;

        nums.push_back(n);

        int lastDigit = n % 10;
        if (lastDigit < 9) {
            generateNumbers((n * 10) + (lastDigit + 1));
        }
        
    }
};