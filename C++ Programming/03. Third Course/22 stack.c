#include <stdio.h>

#define MAX 100
int stack[MAX];
int tos = 0;

void push(int i) {
    if(tos >= MAX) {
        printf("Stack Full\n");
        return;
    }
    stack[tos] = i;
    tos++;
}

int pop() {
    tos--;
    if(tos < 0) {
        printf("Stack Underflow\n");
        return (0);
    }
    return stack[tos];
}
int peek() {
    return stack[tos - 1];
}

int main() {

    push(55);
    push(60);
    push(78);
    push(5);
    push(150);
    int lastValue = peek();
    printf("Last value is %d\n",lastValue);
    pop();
    lastValue = peek();
    printf("Last value is %d\n",lastValue);

    return (0);
}
