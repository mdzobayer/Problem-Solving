#include <bits/stdc++.h>
#define MAX_POWER 25
using namespace std;


vector < int > baseMulti[100000+5];

void preProcess() {
    int i, j;
    for (i = 1; i <= 100000; ++i) {
        baseMulti[i].push_back(1);

        for (j = 1; j < MAX_POWER; ++j) {
            //baseMulti[i][j] = baseMulti[i][j - 1] * i;
            if ((baseMulti[i][j - 1] * i) > 2000000) {
                break;
            }

            baseMulti[i].push_back(baseMulti[i][j - 1] * i);
            
        }
    }

    for (i = 0; i < baseMulti[100000].size(); ++i) {
        cout << baseMulti[100000][i] << " ";
    }
    cout << endl;
}

bool isPalindrome(const vector < int > & arr, int len) {
    int i, j;

    // cout << "isPalindrome Len = " << len << endl;
    // for (i = 0; i < len; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    i = 0;
    j = len - 1;
    while(i < j) {
        if (arr[i] != arr[j]) {
            return false;
        }

        ++i;
        --j;
    }
    

    return true;
}

bool solve (int num, int base) {
    int p = baseMulti[base].size() - 1, len, x = num;
    bool flag = true;
    len = 0;
    vector < int > arr;
    //cout << num << " Debug 1" << endl;
    while(p >= 0) {
        if (baseMulti[base][p] <= num) {
            num -= baseMulti[base][p];
            flag = false;
            arr.push_back(1);
            ++len;
        }
        else if (!flag) {
            arr.push_back(0);
            ++len;
        }
        --p;
    }
    len = arr.size();
    // for (int i = 0; i < len; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //cout << "Debug 2" << endl;
    if (num > 0) return false;

    //cout << "Possible base convert : " << x << endl;

    return isPalindrome(arr, len);
}


int main() {

    int a, b, k, j, Count = 0, i;
    bool flag;

    preProcess();
    cin >> a >> b >> k;

    for (i = a; i <= b; ++i) {
        flag = true;
        for (j = 2; j <= k; ++j) {
            if (solve(i, j)) {
                //cout << i << " is palindrome" << endl;
                flag = false;
            }
        }

        if (flag) {
            ++Count;
        }

    }
    cout << Count << endl;


    return (0);
}