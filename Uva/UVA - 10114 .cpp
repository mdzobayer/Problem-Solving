#include <cstdio>
#include <cstring>

double depreciation[110];

int main() {

    int totalMonth, month, monthCount, i, x;
    double downPayment, cost, rate, carCost, monthPay;
    while(scanf("%d %lf %lf %d", &totalMonth, &downPayment, &cost, &monthCount) == 4) {

        if (totalMonth < 1) {
            break;
        }
        memset(depreciation, 0, sizeof(depreciation));
        for (i = 0; i < monthCount; ++i) {
            scanf("%d %lf", &x, &rate);
            depreciation[x] = rate;
        }
        carCost = downPayment + cost;
        monthPay = cost / totalMonth;
        for (x = 0; x < totalMonth; ++x) {
            rate = (depreciation[x] ? depreciation[x] : rate);
            carCost *= (1.0 - rate);
            if (cost < carCost) {
                //printf("%lf %lf", cost, carCost);
                break;
            }
            cost -= monthPay;
        }
        if (x == 1) {
            printf("1 month\n");
        }
        else {
            printf("%d months\n", x);
        }
    }

    return (0);
}
