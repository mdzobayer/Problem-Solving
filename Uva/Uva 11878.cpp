#include <cstdio>

int main() {

    int num1, num2, result, correctAns, r;
    char operat, oprand;
    correctAns = 0;
    char ques[100];
    while(gets(ques))
    {
        if (sscanf(ques,"%d%c%d=%d", &num1, &operat, &num2, &result) != 4)
            continue;
        switch(operat) {
        case '+':
            r = num1 + num2;
            break;
        case '-':
            r = num1 - num2;

        }
        if (result == r) correctAns++;
    }
    printf("%d\n", correctAns);

    return (0);
}
