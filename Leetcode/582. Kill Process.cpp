class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int i, n = pid.size(), SIZE = 50000 + 1;
        vector< vector<int> > childs(SIZE, vector<int>());
        vector<bool> killed(SIZE, false);
        vector<int> ans;

        for (i = 0; i < n; ++i) {
            childs[ppid[i]].push_back(pid[i]);
        }

        queue<int> q;
        q.push(kill);
        killed[kill] = true;
        ans.push_back(kill);

        while(!q.empty()) {
            int nextChild, child = q.front();
            q.pop();

            for (i = 0; i < childs[child].size(); ++i) {
                nextChild = childs[child][i];
                if (!killed[nextChild]) {
                    killed[nextChild] = true;
                    q.push(nextChild);
                    ans.push_back(nextChild);
                }
            }
        }

        return ans;
    }
};