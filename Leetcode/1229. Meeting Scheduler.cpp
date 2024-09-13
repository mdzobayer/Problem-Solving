class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int pointer1 = 0, pointer2 = 0;

        while(pointer1 < slots1.size() && pointer2 < slots2.size()) {
            int leftIntersection = max(slots1[pointer1][0], slots2[pointer2][0]);
            int rightIntersection = min(slots1[pointer1][1], slots2[pointer2][1]);

            if (rightIntersection - leftIntersection >= duration) {
                return vector<int> {leftIntersection, leftIntersection + duration};
            }

            if (slots1[pointer1][1] < slots2[pointer2][1]) {
                ++ pointer1;
            }
            else {
                ++ pointer2;
            }
        }

        return vector<int>();
    }
};