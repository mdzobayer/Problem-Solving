class Solution {
public:
    bool isPathCrossing(string path) {
        int i, n = path.size();
        bool ans = false;
        set<pair<int,int>> st;

        pair<int,int> point = make_pair(0, 0);
        st.insert(point);
        
        for (i = 0; i < n; ++i) {
            point = nextPoint(point, path[i]);
            if (st.find(point) != st.end()) {
                ans = true;
                break;
            }

            st.insert(point);
        }

        return ans;
    }

    pair<int, int> nextPoint(pair<int,int> point, char & dir) {
        pair<int, int> nextPoint = point;

        if (dir == 'N') nextPoint.first -= 1;
        else if (dir == 'E') nextPoint.second += 1;
        else if (dir == 'S') nextPoint.first += 1;
        else nextPoint.second -= 1;

        return nextPoint;
    }
};