#include <stdio.h>

void recurse(int i) {
    if (i < 10) {

        printf("%d ",i+1);
        recurse(i + 1);
    }
}

int main() {

    recurse(0);

    return (0);
}
