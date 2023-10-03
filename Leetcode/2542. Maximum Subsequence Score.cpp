class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int i; 
        const int n = nums1.size();
        
        vector<pair<int,int>> sortedPair;
        for (i = 0; i < n; ++i) {
            sortedPair.push_back(make_pair(nums2[i], nums1[i]));
        }

        sort(sortedPair.rbegin(), sortedPair.rend());

        long long int aggregateSum = 0, ans;
        priority_queue<int, vector<int>, greater<int>> aggregateElements;

        for (i = 0; i < k; ++i) {
            aggregateSum += sortedPair[i].second;
            aggregateElements.push(sortedPair[i].second);
        }
        ans = (aggregateSum * sortedPair[k - 1].first);

        for (i = k; i < n; ++i) {
            int minElement = aggregateElements.top();
            aggregateElements.pop();

            aggregateSum -= minElement;

            aggregateSum += sortedPair[i].second;
            aggregateElements.push(sortedPair[i].second);

            ans = max(ans, (aggregateSum * sortedPair[i].first));
        }

        return ans;
    }
};