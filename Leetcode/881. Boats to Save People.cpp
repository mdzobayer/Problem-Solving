class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i, j, ans = 0;
        sort(people.begin(), people.end());

        i = 0, j = people.size() - 1;

        while(i <= j) {
            ++ ans;

            if(people[i] + people[j] <= limit) {
                ++i;
            }
            --j;
        }

        return ans;
    }
};