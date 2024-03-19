class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int i, lastTask = -1, ans = 0;
        vector<int> taskCounts(26, 0);

        for (i = 0; i < tasks.size(); ++i) {
            ++taskCounts[tasks[i] - 'A'];
        }
        
        priority_queue<int> q;
        int task;

        for (i = 0; i < 26; ++i) {
            if (taskCounts[i] > 0) {
                q.push(taskCounts[i]);
            }
        }

        while(!q.empty()) {
            
            int cycle = n + 1;
            vector<int> store;

            int taskCount = 0;
            while(cycle -- && !q.empty()) {
                if (q.top() > 1) {
                    store.push_back(q.top() - 1);
                }
                q.pop();
                ++taskCount;
            }

            for (int & x : store) {
                q.push(x);
            }
            
            if(q.empty()) {
                ans += taskCount;
            }
            else ans += n + 1;
        }

        return ans;
    }
};