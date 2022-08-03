#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll numbers[3];

    while(scanf("%lld %lld %lld", &numbers[0], &numbers[1], &numbers[2]) == 3) {

        if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0) break;

        numbers[0] *= numbers[0];
        numbers[1] *= numbers[1];
        numbers[2] *= numbers[2];

        sort(numbers, numbers+3);

        if (numbers[0] + numbers[1] == numbers[2]) {
            puts("right");
        }
        else {
            puts("wrong");
        }
    }

    return (0);
}