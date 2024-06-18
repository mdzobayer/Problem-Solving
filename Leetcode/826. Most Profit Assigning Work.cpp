class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int i, left, right, mid, n = difficulty.size(), m = worker.size();

        vector< pair<int,int> > jobProfile;
        jobProfile.push_back({0, 0});
        for (i = 0; i < n; ++i) {
            jobProfile.push_back({difficulty[i], profit[i]});
        }

        sort(jobProfile.begin(), jobProfile.end());
        for (i = 1; i < n; ++i) {
            jobProfile[i].second = max(jobProfile[i].second, jobProfile[i - 1].second);
        }

        int jobProfit, netProfit = 0;
        for (i = 0; i < m; ++i) {
            left = 0, right = n;
            mid = 0;
            jobProfit = 0;
            
            while(left <= right) {
                mid = (left + right) / 2;

                if (jobProfile[mid].first <= worker[i]) {
                    jobProfit = max(jobProfit, jobProfile[mid].second);
                    left = mid + 1;
                }
                else right = mid - 1;
            }

            netProfit += jobProfit;
        }

        return netProfit;
    }
};