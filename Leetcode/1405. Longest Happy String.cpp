class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue< pair<int, char> > pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while(!pq.empty()) {
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if (ans.length() >= 2 && ans.back() == ch && ans[ans.length() -2] == ch) {
                if (pq.empty()) break;

                auto temp = pq.top();
                pq.pop();

                ans += temp.second;
                if (temp.first - 1 > 0) {
                    pq.push({temp.first - 1, temp.second});
                }
            }
            else {
                -- count;
                ans += ch;
            }

            if (count > 0) {
                pq.push({count, ch});
            }
        }

        return ans;
    }
};