class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i, lastMax, a, b, cnt, n = arr.size();

        if (k >= n) return findMax(arr, n);

        deque<int> dq;

        for (i = 0; i < n; ++i) {
            dq.push_back(arr[i]);
        }

        a = dq.front();
        dq.pop_front();
        b = dq.front();
        dq.pop_front();

        lastMax = max(a, b);
        dq.push_back(min(a, b));
        dq.push_front(lastMax);
        cnt = 1;

        while(cnt < k) {
            a = dq.front();
            dq.pop_front();
            b = dq.front();
            dq.pop_front();

            if (lastMax == max(a, b)) {
                ++ cnt;
                dq.push_back(min(a, b));
                dq.push_front(lastMax);
            }
            else {
                lastMax = max(a, b);

                dq.push_back(min(a, b));
                dq.push_front(lastMax);
                cnt = 1;
            }
        }

        return lastMax;
    }

    int findMax(vector<int>& arr, int len) {
        int maximum = arr[0];
        for (int i = 1; i < len; ++i) {
            maximum = max(maximum, arr[i]);
        }

        return maximum;
    }
};