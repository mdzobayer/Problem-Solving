#include <bits/stdc++.h>

using namespace std;
#define ll long long int
int main() {

    ll n, conn = 0;
    cin >> n;
    conn = n / 100;
    n = n % 100;
    conn += n / 20;
    n = n % 20;
    conn += n / 10;
    n = n % 10;
    conn += n / 5;
    n = n % 5;
    conn += n;

    cout << conn << endl;

    return (0);
}
