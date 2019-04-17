#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, currentRating, x, i, actualRating, test ;
    cin >> test;
    while(test--) {
        cin >> n >> currentRating;
        actualRating = 1500;
        for ( i = 0; i < n; ++i) {
            cin >> x;
            actualRating += x;
        }
        if (actualRating == currentRating) {
            cout << "Correct" << endl;
        }
        else cout << "Bug" << endl;
    }


    return (0);
}