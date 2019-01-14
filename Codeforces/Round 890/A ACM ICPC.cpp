#include <bits/stdc++.h>


using namespace std;


int main() {


    int arr[6], score = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i];
        score += arr[i];
    }

    if(score % 2 != 0) {
        cout << "NO" << endl;
        return (0);
    }
    score >>= 1;

    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            for (int k = j + 1; k < 6; ++k) {
                if((arr[i] + arr[j] + arr[k]) == score) {
                    cout << "YES" << endl;
                    return (0);
                }
            }
        }
    }
    cout << "NO" << endl;


    return (0);
}
