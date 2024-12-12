class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long int ans = 0, item, sqRoot;

        while(k > 0) {
            --k;

            item = pq.top();
            pq.pop();

            sqRoot = sqrt(item);
            pq.push(sqRoot);
            
        }

        while(!pq.empty()) {
            item = pq.top();
            pq.pop();
            ans += item;
        }

        return ans;
    }
};