#include <bits/stdc++.h>


using namespace std;


int main() {

    int test, a, b;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d", &a, &b);
        if (a < b) {
            printf("WeWillEatYou\n");
        }
        else {
            printf("FunkyMonkeys\n");
        }
    }

    return (0);
}
