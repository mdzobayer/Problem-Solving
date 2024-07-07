class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int reminder, ans = numBottles;

        while(numBottles >= numExchange) {
            reminder = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += reminder;
        }

        return ans;
    }
};