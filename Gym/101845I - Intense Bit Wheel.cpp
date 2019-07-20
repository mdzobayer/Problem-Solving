#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int i, n, m, bit, j, round;
    unsigned long long int k, num, tmp;
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; ++i) {
        cin >> num >> k;

        if (k > n) {
            round = k % n;
        }
        else {
            round = k;
        }

        

        deque < int > dq;

        tmp = num;

        while(tmp > 0) {
            bit = (tmp & 1);
            dq.push_front(bit);

            tmp >>= 1;
        }

        while(dq.size() < n) {
            dq.push_front(0);
        }

        // for (int y : dq) {
        //     cout << y << " ";
        // }
        // cout << endl;

        for (j = 0; j < round; ++j) {
            bit = dq.front();
            dq.pop_front();
            dq.push_back(bit);
        }

        num = 0;
        tmp = 1;
        for (deque<int>::iterator it = dq.end() - 1; it >= dq.begin(); --it, tmp *= 2) {
            if (*it == 1) {
                num += tmp;
            }
        }

        cout << num << endl;

        // for (int y : dq) {
        //     cout << y << " ";
        // }
        // cout << endl;
        
    }


    return (0);
}