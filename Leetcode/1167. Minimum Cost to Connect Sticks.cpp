class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int cost = 0, stick = 0, i;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int item : sticks) {
            pq.push(item);
        }

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            cost += x + y;
            pq.push(x + y);
        }

        return cost;
    }
};