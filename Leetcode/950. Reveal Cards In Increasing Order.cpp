class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int i, place = 0, n = deck.size();
        vector<int> ans(n);
        bool select = true;

        sort(deck.begin(), deck.end());

        i = 0;
        while(i < n) {
            if (ans[place] == 0) {
                if (select) {
                    ans[place] = deck[i++];
                }
                select = !select;
            }
            
            place = (place + 1) % n;
        }

        return ans;
    }
};