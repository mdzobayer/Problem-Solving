#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ll n, time = 0;
    char ch;
    cin >> n >> ch;
    time = (n - 1 ) / 4 * 16;
    n %= 4;

    if (n == 2 || n == 0) time += 7;
    if (ch == 'f') time++;
    if (ch == 'e') time += 2;
    if (ch == 'd') time += 3;
    if (ch == 'a') time += 4;
    if (ch == 'b') time += 5;
    if (ch == 'c') time += 6;

    cout << time << endl;

    return (0);
}
