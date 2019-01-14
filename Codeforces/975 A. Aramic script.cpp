#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i;
    string str;
    set < set < char > > box;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> str;
        box.emplace(str.begin(), str.end());
    }
    cout << box.size() << endl;

    return (0);
}
