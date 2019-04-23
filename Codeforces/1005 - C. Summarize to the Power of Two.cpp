#include <bits/stdc++.h>

long long int num[120000];

using namespace std;



int main() {

    //freopen("in.txt", "r", stdin);

    long long int n, i, x, y, j, arr[35], cnn = 0;

    map < long long int, int > numbers;

    arr[0] = 0;
    arr[1] = 1;
    for (i = 2; i < 33; ++i) {
        arr[i] = arr[i - 1] * 2;
        //cout << arr[i] << " ";
    }
    //cout << endl;

    scanf("%lld", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &x);

        num[i] = x;
        numbers[x] += 1;
    }
    
    bool flag;

    sort(num, num+n);

    for (j = 0; j < n; ++j) {

        y = num[j];
        flag = false;

        for (i = 1; i < 33; ++i) {
            x = arr[i] - y;

            if (x <= 0) continue;
            else if (x == y) {
                if (numbers[x] > 1) {
                    flag = true;
                    break;
                }
            }
            else if (numbers.find(x) != numbers.end()) {
                if (numbers[x] > 0) {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) {
            //cout << y << endl;
            ++cnn;
        }
    }
    
    cout << cnn << endl;

    return (0);
}