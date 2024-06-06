class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        int i;
        map<int, int> cardCount;
        for (int item : hand) {
            ++ cardCount[item];
        }

        while(!cardCount.empty()) {
            int currentCard = cardCount.begin()->first;

            for(i = 0; i < groupSize; ++i) {
                if (cardCount[currentCard + i] == 0) return false;

                int cnt = -- cardCount[currentCard + i];
                if (cnt == 0) cardCount.erase(currentCard + i);
            }
        }

        return true;
    }
};