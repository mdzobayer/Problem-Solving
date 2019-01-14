#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int outcome, len, l1, l2;

    if (argc != 3) {
        printf("Incorrect number of arguments.");
        exit(1);
    }
    /* find the length of shortest string */
    l1 = strlen(argv[1]);
    l2 = strlen(argv);
    len = l1 < l2 ? l1 : l2;
    outcome = memcmp(argv[1], argv[2], len);
    if (!outcome)
        printf("Equal");
    else if(outcome < 0)
        printf("First less than second");
    else
        printf("First greater than second");

    return (0);
}
