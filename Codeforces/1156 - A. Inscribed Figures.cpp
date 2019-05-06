#include <bits/stdc++.h>

using namespace std;

int main() {    

    int n, i, arr[110];
    cin >> n;

    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int point = 0;
    for (i = 1; i < n; ++i) {
        if (arr[i] == 2 && arr[i - 1] == 3) {
            cout << "Infinite" << endl;
            return (0);
        }
        else if (arr[i] == 3 && arr[i - 1] == 2) {
            cout << "Infinite" << endl;
            return (0);
        }
        else if (arr[i] == arr[i - 1]) {
            cout << "Infinite" << endl;
            return (0);
        }
        else {
            if (arr[i] == 1 && arr[i-1] == 2) {
                point += 3;
            }
            else if (arr[i] == 2 && arr[i-1] == 1) {
                point += 3;
            }
            else if (arr[i] == 1 && arr[i-1] == 3) {
                point += 4;
            }
            else if (arr[i] == 3 && arr[i-1] == 1) {
                point += 4;
            }
        }
    }
    cout << "Finite" << endl;
    cout << point << endl;

    return (0);
}