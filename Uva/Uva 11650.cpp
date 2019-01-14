#include <cstdio>

int main() {

int test, hour, min;
    scanf("%d", &test);
    while(test--){
        scanf("%d:%d", &hour, &min);
            hour = 11 - hour + ( min == 0);
            if( hour <= 0)
                hour += 12;
            if(hour)
                min = 60 - min;
            if(min == 60)
                min = 0;

            printf("%02d:%02d\n", hour, min);
        }

    return (0);
}
