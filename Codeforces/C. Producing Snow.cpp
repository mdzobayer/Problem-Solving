
#include <bits/stdc++.h>


using namespace std;

#define LLI long long int

LLI arr[100000+5], n;


int main() {
    LLI i, remain = 0, x, res, ran, j, y;
    queue < LLI > que;
    scanf("%lld", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
    for (i = 0; i < n; ++i) {
        scanf("%lld", &x);
        //res = abs(x - arr[i]);
        //res += abs(remain - x);
        que.push(arr[i]);
        ran = que.size();
        res = 0;
        for (j = 0; j < ran; ++j) {
            y = que.front();

            que.pop();
            if (y > x) {
                que.push(y - x);
                //cout << "pushed   " << y - x << endl;
                res += x;
            }
            else {
                res += y;
            }
        }
//        res = 0;
//        if (remain >= x) {
//            remain -= x;
//            res += x;
//        }
//        else {
//            res += remain;
//            remain  = 0;
//        }
//        if (arr[i] >= x) {
//            remain += (arr[i] - x);
//            res += x;
//        }
//        else {
//            res += arr[i];
//        }
        printf("%lld ", res);
        //cout << endl << endl;
    }

    return (0);
}
