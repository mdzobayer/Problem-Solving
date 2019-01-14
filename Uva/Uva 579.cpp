#include <cstdio>
//#include <cstdlib>

double abs(double x) {
    if (x < 0) return (x * -1.0);
    return x;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double hour, minute, hh, mm;
    while(scanf("%lf:%lf", &hour, &minute) == 2) {
        if (hour == 0 && minute == 0) break;

        if (hour == 12) hour = 0;
        hh = hour * 30.0 + (minute / 60) * 30.0;
        mm = minute * 6.0;
        //printf("%lf %lf %lf\n", hh, mm, (double)abs(hh - mm));
        if (abs(hh - mm) > 180) {
            printf("%.3lf\n", (double)(360.0 - abs(hh - mm)));
        }
        else {
            printf("%.3lf\n", (double)abs(hh - mm));
        }

    }

    return (0);
}
