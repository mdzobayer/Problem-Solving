class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;

        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        sort(numStrings.begin(), numStrings.end(), [](string & a, string & b) {return a + b > b + a;});

        if (numStrings.front() == "0") return numStrings.front();

        string largestNum;
        for (string & strNum : numStrings) {
            largestNum += strNum;
        }

        return largestNum;
    }
};