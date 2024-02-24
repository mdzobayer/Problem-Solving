class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knownPerson(n, 1e9);
        int i;

        knownPerson[0] = 0;
        knownPerson[firstPerson] = 0;

        vector<vector<pair<int, int>>> ajlist(n);
        for (i = 0; i < meetings.size(); ++i) {
            ajlist[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            ajlist[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});

        while(!q.empty()) {
            auto [person, time] = q.front();
            q.pop();

            for (auto [nextPerson, t] : ajlist[person]) {
                if (t >= time && knownPerson[nextPerson] > t) {
                    knownPerson[nextPerson] = t;
                    q.push({nextPerson, t});
                }
            }
        }

        vector<int> ans;

        for (i = 0; i < n; ++i) {
            if (knownPerson[i] != 1e9) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};