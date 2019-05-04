#include <bits/stdc++.h>

using namespace std;
#define SIZE 5000000+10
#define ll long long int

bool prime[SIZE];
ll answers[SIZE];
double answerD[SIZE];
vector < int > primes;

void sieve() {
    int i, j, sz;

    for (i = 4; i < SIZE; i += 2) {
        prime[i] = true;
        answerD[i] *= (1.0 - (1.0 / (float) i));
    }
    //sz = sqrt(SIZE) + 1;
    for (i = 3; i < SIZE; i += 2) {
        if (prime[i] == false) {
            for (j = i * 2; j < SIZE; j += i) {
                prime[j] = true;
                answerD[j] *= (1.0 - (1.0 / (float) j));
            }
        }
    }

    // for (i = 2; i < SIZE; ++i) {
    //     if (prime[i] == false)
    //         primes.push_back(i);
    // }
}

ll squarePHI (int x) {
    double result = x;
    
    for (int y : primes) {
        if (y > x) break;

        if (x % y == 0) {
            result *= (1.0 - (1.0 / (float) y));
        }
    }

    ll sq = (ll) result;

    return sq * sq;
}



void generateAns() {

    

    answers[0] = answers[1] = 0;

    int i;
    for (i = 2; i < SIZE; ++i) {
        answerD[i] = i;
    }
    
    sieve();
    printf("Sieve done\n");

    for (i = 2; i < SIZE; ++i) {
        answers[i] = answers[i - 1] + ((ll)answerD[i] * (ll)answerD[i]);
    }

}



int main() {

    generateAns();
    printf("Value Calculation done\n");
    int test, t, a, b;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %lld\n", t, (ll) answers[b] - answers[a - 1]);
    }

    return (0);
}
