#include <bits/stdc++.h>
#define SIZE 100000+10
using namespace std;

int coPrimes[SIZE];

vector < int > xCoPrime [1000000+5];

int primeFactor(int n) 
{ 
    // float result = n; 
    // for (int p = 2; p * p <= n; ++p) { 

    //     if (n % p == 0) { 

    //         while (n % p == 0) 
    //             n /= p; 
    //         result *= (1.0 - (1.0 / (float)p)); 
    //     } 
    // } 
    // if (n > 1) 
    //     result *= (1.0 - (1.0 / (float)n)); 
  
    // return (int)result; 

    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
} 

void generateCoPrimes(int n) {

    int i;
    for (i = 1; i <= n; ++i) {
        coPrimes[i] = primeFactor(i);
        xCoPrime[coPrimes[i]].push_back(i);
    }    
}


int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("coPrime.txt", "w", stdout);

    int n, q, x, a, b, i, ans, a1, b1;
    scanf("%d %d", &n, &q);

    vector < int >::iterator ai, bi;

    generateCoPrimes(n);

    // for (i = 0; i <= xCoPrime[72].size(); ++i) {
    //     printf("%d ", xCoPrime[72][i]);
    // }

    //cout << coPrimes[10019] << endl;

    for (i = 0; i < q; ++i) {
        scanf("%d %d %d", &a, &b, &x);

        ai = lower_bound(xCoPrime[x].begin(), xCoPrime[x].end(), a);
        a1 = ai - xCoPrime[x].begin();

        bi = lower_bound(xCoPrime[x].begin(), xCoPrime[x].end(), b);
        b1 = bi - xCoPrime[x].begin();

        if (b1 >= xCoPrime[x].size()) --b1;
        else if (xCoPrime[x][b1] > b) --b1;

        //cout << b1 << " " << a1 << endl;

        ans = b1 - a1 + 1;
        printf("%d\n", ans);
    }

    return (0);
}