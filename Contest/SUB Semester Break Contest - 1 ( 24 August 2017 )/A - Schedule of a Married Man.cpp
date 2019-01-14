#include <cstdio>

int min(int x, int y) {
    return x < y ? x : y;
}
int max(int x, int y) {
    return x > y ? x : y;
}

int main() {

    int test, t, whs, wms, whe, wme, mhs, mms, mhe, mme, s1, s2, t1, t2;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d:%d %d:%d", &whs, &wms, &whe, &wme);
        scanf("%d:%d %d:%d", &mhs, &mms, &mhe, &mme);
        s1 = whs * 60 + wms;
        s2 = mhs * 60 + mms;
        t1 = whe * 60 + wme;
        t2 = mhe * 60 + mme;
        whs = max (s1, s2);
        wms = min (t1, t2);
        printf("Case %d: ", t);
        if (whs <= wms) {
            printf("Mrs Meeting\n");
        }
        else {
            printf("Hits Meeting\n");
        }
    }

    return (0);
}
