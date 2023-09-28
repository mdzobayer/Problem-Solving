class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int i = 0;
        vector<int> sortedPotions, ans;
        
        for (i = 0; i < potions.size(); ++i) {
            sortedPotions.push_back(potions[i]);
        }
        sort(sortedPotions.begin(), sortedPotions.end());

        for (i = 0; i < spells.size(); ++i) {
            ans.push_back(successPotionCount(spells[i], sortedPotions, success));
        }

        return ans;
    }

    int successPotionCount(int spell, vector<int>& potions, long long success) {
        int left = 0, mid, right = potions.size() - 1;
        int index = -1, ans = 0;
        long long int tempProduct;

        while(left <= right) {
            mid = left + right;
            mid >>= 1;

            tempProduct;
            if ((potions[mid] * (long long int)spell) >= success) {
                index = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if (index > -1) {
            ans = potions.size() - index;
        }

        return ans;
    }
};