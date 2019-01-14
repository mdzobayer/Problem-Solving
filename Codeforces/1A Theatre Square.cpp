#include <bits/stdc++.h>


using namespace std;

int main() {

    long long int n, m, a;
    cin >> n >> m >> a;

    long long int ans1 = ceil((double)n/a);
    long long int ans2 = ceil((double)m/a);

    cout << (ans1 * ans2) << endl;

    return (0);
}
