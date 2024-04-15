/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> knownCount(n, 0), ownCount(n, 0);

        int i, j;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i != j && knows(i, j)) {
                    ++ knownCount[j];
                    ++ ownCount[i];
                }
            }
        }

        for (i = 0; i < n; ++i) {
            if (knownCount[i] == n - 1 && ownCount[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};