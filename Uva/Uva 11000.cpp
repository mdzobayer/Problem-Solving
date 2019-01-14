#include <cstdio>
long long int male[100005], total[100005];
int main(int argc, char **argv) {
    //freopen("input.txt", "r", stdin);
    long long int i, input, newFemale, newMale, oldFemale;
    male[0] = 0;
    total[0] = 1;
    newFemale = newMale = 0;
    oldFemale = 1;
    for (i = 1; i <= 100000; ++i) {
        male[i] = total[i - 1];
        newMale = oldFemale;
        oldFemale += newFemale;
        newFemale = newMale;
        total[i] += oldFemale;
        total[i] += male[i];
    }
    while(scanf("%lld", &input) == 1) {
        if (input < 0) {
            break;
        }
        printf("%lld %lld\n", male[input], total[input]);
    }

    return (0);
}
