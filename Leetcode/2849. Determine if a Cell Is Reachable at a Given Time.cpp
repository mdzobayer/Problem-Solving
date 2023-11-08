class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int distance = eightDiagonalDistance(sx, sy, fx, fy);
        
        if (distance == 0 && t == 1) return false;
        return distance <= t;
    }

    int eightDiagonalDistance(int sx, int sy, int fx, int fy) {
        return max(abs(sx - fx), abs(sy - fy));
    }
};