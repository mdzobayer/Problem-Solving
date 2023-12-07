class Solution {
public:
    bool isPalindrome(int x) {
        long long int revNum = 0, copyOfX = x;

        while(copyOfX > 0) {
            revNum *= 10;
            revNum += copyOfX % 10;
            copyOfX /= 10;
        }

        return x == revNum;
    }
};