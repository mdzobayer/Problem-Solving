class Solution {
public:
    int passThePillow(int n, int time) {
        int i, t, dir = 1;

        t = 0;
        i = 0;
        while(t < time) {
            i += dir;

            if (i == 0 || i == n - 1) {
                dir = dir == 1 ? -1 : 1;
            }
            ++t;
        }

        return i + 1;
    }
};