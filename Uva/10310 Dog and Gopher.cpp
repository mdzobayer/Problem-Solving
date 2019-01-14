#include <bits/stdc++.h>
#define SIZE 1005

using namespace std;

double holes[2][SIZE];

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, i;
    double gx, gy, dx, dy, x, y, dis1, dis2;
    bool flag;

    while(scanf("%d", &n) == 1) {
        scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);

        for (i = 0; i < n; ++i) {
            scanf("%lf %lf", &holes[0][i], &holes[1][i]);
        }
        flag = true;
        for (i = 0; i < n; ++i) {
            dis1 = sqrt(((gx-holes[0][i])*(gx-holes[0][i])) + ((gy-holes[1][i])*(gy-holes[1][i])));

            dis2 = sqrt(((dx-holes[0][i])*(dx-holes[0][i])) + ((dy-holes[1][i])*(dy-holes[1][i])));
            //cout << "--- " << dis1 << " " << dis2 << endl;
            if ((dis1*2.0) <= dis2) {
                printf("The gopher can escape through the hole at (%0.3f,%0.3f).\n",holes[0][i], holes[1][i]);
                flag = false;
                break;
            }
        }
        if (flag)
            printf("The gopher cannot escape.\n");
    }

    return (0);
}
