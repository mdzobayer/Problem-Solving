#include <cstdio>

#define LLI long long int

int main() {

    int cm, cd, cy, bm, bd, by, test, t;
    LLI cTotalDay, bTotalDay;
    scanf("%d", &test);
    for(t = 1; t <= test; ++t) {
        scanf("%d/%d/%d", &cd, &cm, &cy);
        scanf("%d/%d/%d", &bd, &bm, &by);
        cTotalDay = cd;
        cTotalDay += (cm * 30);
        cTotalDay += ((cy * 12) * 30);

        bTotalDay = bd;
        bTotalDay += (bm * 30);
        bTotalDay += ((by * 12) * 30);

        printf("Case #%d: ", t);
        if (bTotalDay == cTotalDay) {
            printf("0\n");
        }
        else if (bTotalDay > cTotalDay) {
            printf("Invalid birth date\n");
        }
        else {
            cTotalDay -= bTotalDay;
            cm = cTotalDay / 30;
            cy = cm / 12;
            if (cy > 130) {
                printf("Check birth date\n");
            }
            else {
                printf("%d\n", cy);
            }
        }
    }


    return (0);
}
