#include <cstdio>

int main() {

    int n, arr[110];
    bool unimodal, incr, decr, cons;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    unimodal = true;
    incr = decr = cons = true;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1] && incr) {
            unimodal = true;
            incr = true;
            //printf("incr\n");
        }
        else if (arr[i] == arr[i - 1] && cons) {
            incr = false;
            unimodal = true;
            //printf("cons\n");
        }
        else if (arr[i] < arr[i - 1] && decr){
            unimodal = true;
            cons = false;
            incr = false;
            //printf("decr\n");
        }
        else {
            unimodal = false;
            cons = false;
            incr = false;
            decr = false;
            break;
        }

    }
    if (unimodal) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return (0);
}
