#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, i, numberOfGroups, currentGroupBlockCount;
    string previousMagnet, currentMagnet;

    numberOfGroups = currentGroupBlockCount = 0;

    cin >> n;
    cin >> previousMagnet;
    ++currentGroupBlockCount;
    for (i = 1; i < n; ++i) {
        cin >> currentMagnet;

        if (previousMagnet == currentMagnet) {
            ++currentGroupBlockCount;
        } else {
            currentGroupBlockCount = 1;
            ++numberOfGroups;
        }

        previousMagnet = currentMagnet;
    }

    if (currentGroupBlockCount > 0) {
        ++numberOfGroups;
    }

    cout << numberOfGroups << endl;


    return (0);
}