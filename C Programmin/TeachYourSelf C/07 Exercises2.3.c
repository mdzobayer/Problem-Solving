#include <stdio.h>

void display(char *mgs) {
    if(*mgs) {
        //putchar(*mgs);
        *mgs++;
        display(mgs);
    }
    *mgs--;
    putchar(*mgs);
}

int main() {

    display("Eli\n");

    return (0);
}
