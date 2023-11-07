class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int i, ans = 0, extra, n = dist.size();
        vector<int> arrivalTime;

        for (i = 0; i < n; ++i) {
            extra = 0;
            if (dist[i] % speed[i] > 0) {
                extra = 1;
            }
            
            arrivalTime.push_back((dist[i] / speed[i]) + extra);
        }

        sort(arrivalTime.begin(), arrivalTime.end());

        for (i = 0; i < n; ++i) {
            if (arrivalTime[i] > i) ++ ans;
            else break;
        }

        return ans;
    }
};