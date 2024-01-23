class Solution {
    int ans;
public:
    int maxLength(vector<string>& arr) {
        vector<bool> visited(26, false);
        ans = 0;

        solve(0, arr, visited);
        return ans;
    }

    void solve(int index, vector<string>& arr, vector<bool>& visited) {
        if (index >= arr.size()) {
            ans = max(ans, CountVisited(visited));
            return;
        }

        if (isPossible(index, arr, visited)) {
            mark(index, arr, visited, true);
            solve(index + 1, arr, visited);
            mark(index, arr, visited, false);
        }

        solve(index + 1, arr, visited);
    }

    int CountVisited(vector<bool>& visited) {
        int i, cnt = 0;
        for (i = 0; i < 26; ++i) {
            if (visited[i]) {
                ++cnt;
            }
        }

        return cnt;
    }

    bool isPossible(const int index, vector<string>& arr, vector<bool>& visited) {
        int i;
        bool possible = true;
        vector<bool> selfDuplicate(26, false);

        for (i = 0; i < arr[index].size(); ++i) {
            if (visited[arr[index][i] - 'a'] || selfDuplicate[arr[index][i] - 'a']) {
                possible = false;
                break;
            }

            selfDuplicate[arr[index][i] - 'a'] = true;
        }

        return possible;
    }

    void mark(const int index, vector<string>& arr, vector<bool>& visited, bool value) {
        int i;
        for (i = 0; i < arr[index].size(); ++i) {
            visited[arr[index][i] - 'a'] = value;
        }
    }
};