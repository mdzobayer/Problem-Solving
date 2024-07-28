class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector< vector<int> > ajlist(n + 1);

        for (auto & edge : edges) {
            ajlist[edge[0]].push_back(edge[1]);
            ajlist[edge[1]].push_back(edge[0]);
        }

        vector<int> freq(n + 1, 0), dist1(n + 1, numeric_limits<int>::max()), dist2(n + 1, numeric_limits<int>::max());

        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > minHeap;

        minHeap.push({0, 1});
        dist1[1] = 0;

        while(!minHeap.empty()) {
            auto [timeTaken, node] = minHeap.top();
            minHeap.pop();

            ++ freq[node];

            if (freq[node] == 2 && node == n) return timeTaken;

            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            }
            else {
                timeTaken += time;
            }

            for (int neighbor : ajlist[node]) {
                if (freq[neighbor] == 2) continue;
                
                if (dist1[neighbor] > timeTaken) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = timeTaken;
                    minHeap.push({timeTaken, neighbor});
                }
                else if (dist2[neighbor] > timeTaken && dist1[neighbor] != timeTaken) {
                    dist2[neighbor] = timeTaken;
                    minHeap.push({timeTaken, neighbor});
                }
            }
        }

        return 0;
    }
};