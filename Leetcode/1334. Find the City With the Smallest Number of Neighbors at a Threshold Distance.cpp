class Solution {
public:
    void floydWarshall(vector< vector<int> > & distance, int n) {
        int i, j, k;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < n; ++k) {
                    distance[k][j] = min(distance[k][j], distance[k][i] + distance[i][j]);
                }
            }
        }
    }

    static bool compare(const pair<int, int> & a, const pair<int, int> & b) {
        if (a.first < b.first) return true;
        else if (a.first > b.first) return false;

        return a.second > b.second;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector< vector<int> > distance(n, vector<int>(n, 100000));
        int i, j, count;
        
        for (i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }

        for (auto edge : edges) {
            distance[edge[0]][edge[1]] = min(distance[edge[0]][edge[1]], edge[2]);
            distance[edge[1]][edge[0]] = min(distance[edge[1]][edge[0]], edge[2]);
        }

        floydWarshall(distance, n);
        vector< pair<int, int> > list;
        for (i = 0; i < n; ++i) {
            count = 0;
            for (j = 0; j < n; ++j) {
                if (distance[i][j] <= distanceThreshold) {
                    ++ count;
                }
            }
            
            list.push_back(make_pair(count, i));
        }

        sort(list.begin(), list.end(), compare);

        return list.front().second;
    }
};