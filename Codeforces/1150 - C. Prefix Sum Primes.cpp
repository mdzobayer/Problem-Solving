#include <bits/stdc++.h>

using namespace std;

bool prime[400000 + 10];

vector < int > primes;

void sieve() {

    int i, j, sz;
    //primes.push_back(1);
    primes.push_back(2);
    for (i = 4; i <= 400000; i += 2) {
        prime[i] = true;
    }
    sz = sqrt(400000) + 1;
    for (i = 3; i <= sz; i += 2) {
        if (prime[i] == false){
            primes.push_back(i);
            for (j = i * i; j <= 400000; j += i) {
                prime[j] = true;
            }
        }
    }
}

int main() {

    //sieve();

    int i, n, x, cnn[3];
    cnn[0] = cnn[1] = cnn[2] = 0; 

    // for (int i = 0; i < 100; ++i) {
    //     cout << primes[i] << " ";
    // }

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++cnn[x];
    }

    int prefix = 0, pidx = 0, y;
    string s = "";

    if (cnn[2] > 0 && cnn[1] > 0) {
        cout << "2 1 ";
        cnn[2] -= 1;
        cnn[1] -= 1;
    }


    while(cnn[2] > 0 || cnn[1] > 0) {
        if (cnn[2] > 0) {
            cout << "2 ";
            --cnn[2];
        }
        else {
            cout << "1 ";
            --cnn[1];
        }
    }
    cout << endl;

    return (0);
}