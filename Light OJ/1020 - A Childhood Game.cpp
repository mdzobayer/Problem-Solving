#include <bits/stdc++.h>


using namespace std;


int main() {

    //freopen("in.txt","r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, n;
    char s[20];
    scanf("%d",&test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %s", &n, &s);
        printf("Case %d: ", t);
        if (s[0] == 'A') {
            if (n % 3 == 1)
                puts("Bob");
            else puts("Alice");
        }
        else {
            if (n % 3 == 0)
                puts("Alice");
            else puts("Bob");
        }
    }

    return (0);
}
