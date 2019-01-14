#include <cstdio>
using namespace std;

int n;
char x[110];

int main() {

    scanf("%d\n", &n);
    while(n--) {
        scanf("0.%[0-9]...\n", &x);
        printf("the digits are 0.%s\n", x);
    }

    return (0);
}
