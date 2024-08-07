class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convertToWord(num);
    }

    const vector<string> belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string convertToWord(int num) {
        if (num < 10) {
            return belowTen[num];
        }

        if (num < 20) {
            return belowTwenty[num - 10];
        }

        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 ? " " + convertToWord(num % 10) : "");
        }

        if (num < 1000) {
            return convertToWord(num / 100) + " Hundred" + (num % 100 ? " " + convertToWord(num % 100) : "");
        }

        if (num < 1000000) {
            return convertToWord(num / 1000) + " Thousand" + (num % 1000 ? " " + convertToWord(num % 1000) : "");
        }

        if (num < 1000000000) {
            return convertToWord(num / 1000000) + " Million" + (num % 1000000 ? " " + convertToWord(num % 1000000) : "");
        }

        return convertToWord(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + convertToWord(num % 1000000000) : ""); 
    }
};