
#include <bits/stdc++.h>


using namespace std;

int point[200000+5];

int segment[200000+5];


int main() {

    //freopen("in.txt", "r", stdin);

    int i, q, n, l, r;
    bool minusAns, secJar;



    scanf("%d", &q);
    while(q--) {
        secJar = minusAns = false;
        memset(point, 0, sizeof(point));
        memset(segment, 0, sizeof(segment));


        scanf("%d", &n);

        scanf("%d %d", &l, &r);
        point[l] = 1;
        point[r] = 1;
        segment[0] = 1;

        for (i = 1; i < n; ++i) {
            scanf("%d %d", &l, &r);
            //printf("point %d %d\n", point[l], point[r]);

            if(point[l] != point[r] && (point[l] != 0 && point[r] != 0)) {
                minusAns = true;
            }
            else if(point[l] == 0 && point[r] != 0) {
                point[l] = point[r];
                segment[i] = point[r];
            }
            else if(point[r] == 0 && point[l] != 0) {
                point[r] = point[l];
                segment[i] = point[l];
            }
            else if (point[r] > 0 || point[l] > 0) {

            }
            else {
                point[r] = point[l] = 2;
                segment[i] = 2;
                secJar = true;
                //cout << "Debug 1" << endl;
            }
        }

        if(minusAns || secJar == false) {
            printf("-1\n");
        }
        else {
            printf("%d", segment[0]);
            for (i = 1; i < n; ++i) {
                printf(" %d", segment[i]);
            }
            puts("");
        }
    }


    return (0);
}
