#include <bits/stdc++.h>

using namespace std;
#define SIZE 5000000+10
#define ull unsigned long long int

bool prime[SIZE];
//ll answers[SIZE];
ull answerD[SIZE];

void sieve() {
    int i, j, sz;
    answerD[2] = 1;
    for (i = 4; i < SIZE; i += 2) {
        prime[i] = true;
        answerD[i] *= (1.0 - (1.0 / 2.0));
    }
    //sz = sqrt(SIZE) + 1;
    for (i = 3; i < SIZE; i += 2) {
        if (prime[i] == false) {
            answerD[i] = i - 1;
            for (j = i * 2; j < SIZE; j += i) {
                prime[j] = true;
                answerD[j] *= (1.0 - (1.0 / (double) i));
            }
        }
    }

    // for (i = 2; i < SIZE; ++i) {
    //     if (prime[i] == false)
    //         primes.push_back(i);
    // }
}

// ll squarePHI (int x) {
//     double result = x;
    
//     for (int y : primes) {
//         if (y > x) break;

//         if (x % y == 0) {
//             result *= (1.0 - (1.0 / (float) y));
//         }
//     }

//     ll sq = (ll) result;

//     return sq * sq;
// }



void generateAns() {

    answerD[0] = answerD[1] = 0;

    ull i;
    for (i = 2; i < SIZE; ++i) {
        answerD[i] = i;
    }
    
    sieve();
    //printf("Sieve done\n");

    for (i = 2; i < SIZE; ++i) {
        answerD[i] = (answerD[i] * answerD[i]);
        answerD[i] += answerD[i - 1];
    }

}



int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    generateAns();
    //printf("Value Calculation done\n");
    int test, t, a, b;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", t, (ull) (answerD[b] - answerD[a - 1]));
    }

    return (0);
}
