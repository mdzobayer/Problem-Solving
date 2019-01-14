#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll n) {

    for (ll i = 3; i * i <= n; ++i) {
        if(n % i == 0)
            return i;
    }
    return n;
}


int main() {

    long long int n;

    long long int j, step = 0, res;
    cin >> n;

    if(n % 2 != 0){
        ++step ;

        n -= solve(n);
    }

    if(n % 2 == 0) {
        step += n / 2;
    }
    cout << step << endl;

    return (0);
}
