class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i, need, n = heights.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (i = 1; i < n; ++i) {
            need = heights[i] - heights[i - 1];

            if (need <= 0) continue;
            minHeap.push(need);

            if (minHeap.size() <= ladders) continue;

            bricks -= minHeap.top();
            minHeap.pop();
            if (bricks < 0) break;
        }

        return i - 1;
    }
};