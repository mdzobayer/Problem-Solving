class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int i, a, b, n = positions.size();
        vector< pair<int, pair<int, char> > > line;
        vector<int> rightDir, ans;

        for (i = 0; i < n; ++i) {
            line.push_back({positions[i], {i, directions[i]}});
        }

        sort(line.begin(), line.end());

        for (i = 0; i < line.size(); ++i) {
            if (line[i].second.second == 'R') {
                rightDir.push_back(i);
                continue;
            }
            
            while (rightDir.size() > 0) {
                a = line[rightDir.back()].second.first;
                b = line[i].second.first;

                if (healths[a] > healths[b]) {
                    -- healths[a];
                    healths[b] = 0;
                    break;
                }
                else if (healths[a] < healths[b]) {
                    -- healths[b];
                    healths[a] = 0;
                    rightDir.pop_back();
                }
                else {
                    healths[b] = 0;
                    healths[a] = 0;
                    rightDir.pop_back();
                    break;
                }
            }
        }

        for (i = 0; i < n; ++ i) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};