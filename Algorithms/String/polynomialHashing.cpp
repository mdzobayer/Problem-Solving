#include <bits/stdc++.h>
#define SIZE 100
using namespace std;

long long int primeMultipier = 3, primeMod = 97;
long long int p[SIZE], h[SIZE];
string s;

long long int filter (long long int x) {
    if (x >= 0) return x;
    return (primeMod + x);
}

int main() {
    
    s = "ABABCDEABCD";

    int i;


    p[0] = 1;
    for (i = 1; i < SIZE; ++i) {
        p[i] = (p[i - 1] * primeMultipier) % primeMod;
    }

    h[0] = s[0];
    for (i = 1; i < s.size(); ++i) {
        h[i] = ((h[i - 1] * primeMultipier) + s[i]) % primeMod;
    }
    cout << "Full string hash = " << (h[s.size() - 1] % primeMod) << endl;

    int a, b;
    a = 3;
    b = 5;
    cout << filter(((h[b] - h[a - 1] * p[b - a + 1])) % primeMod) << endl;
    a = 8;
    b = 10;
    cout << filter(((h[b] - h[a - 1] * p[b - a + 1])) % primeMod) << endl;


    a = 0;
    b = 1;
    cout << filter(h[b]) << endl;
    a = 2;
    b = 3;
    cout << filter(((h[b] - h[a - 1] * p[b - a + 1])) % primeMod) << endl;
    a = 7;
    b = 8;
    cout << filter(((h[b] - h[a - 1] * p[b - a + 1])) % primeMod) << endl;

    return (0);
}