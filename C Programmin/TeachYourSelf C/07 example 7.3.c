#include <stdio.h>

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {

    int firstNumber, secondNumber;

    firstNumber = 100;
    secondNumber = 200;

    printf("FirstNumber is %d and SecondNumber is %d\n",firstNumber, secondNumber);
    swap(&firstNumber, &secondNumber);
    printf("FirstNumber is %d and SecondNumber is %d\n",firstNumber, secondNumber);

    return (0);
}
