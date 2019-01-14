#include <cstdio>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
int main() {

    int test, i, n, reqDays, j, d;
    string str;
    scanf("%d\n", &test);
    for (i = 1; i <= test; ++i) {
        scanf("%d\n", &n);
        std::map<string, int> sparrowAbility;
        for (j = 0; j < n; ++j) {
            std::cin >> str >> reqDays;
            getchar();
            sparrowAbility.insert(std::pair<string, int>(str, reqDays));
        }
        scanf("%d", &d);
        getchar();
        cin >> str;
        getchar();
        if (sparrowAbility.find(str) != sparrowAbility.end()) {
            if (sparrowAbility[str] <= d)
                printf("Case %d: Yesss\n", i);
            else if (sparrowAbility[str] <= d + 5)
                printf("Case %d: Late\n", i);
            else
                printf("Case %d: Do your own homework!\n", i);
        }
        else
            printf("Case %d: Do your own homework!\n", i);
    }

    return (0);
}
