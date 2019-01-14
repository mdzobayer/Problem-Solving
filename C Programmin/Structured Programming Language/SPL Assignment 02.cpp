/* Program to display which type of input are taken from keystroke */
#include <stdio.h>

int main() {

    char ch;

    printf("Enter any key: ");
    scanf("%c",&ch);
    switch(ch) {
        case 'a': case 'A': case 'e': case 'E': case 'i':
        case 'I': case 'o': case 'O': case 'u': case 'U':
            printf("You type a Vowel keyword %c \n",ch);
            break;

        case 'b': case 'B': case 'c': case 'C': case 'd':
        case 'D': case 'f': case 'F': case 'g': case 'G':
        case 'h': case 'H': case 'j': case 'J': case 'k':
        case 'K': case 'l': case 'L': case 'm': case 'M':
        case 'n': case 'N': case 'p': case 'P': case 'q':
        case 'Q': case 'r': case 'R': case 's': case 'S':
        case 't': case 'T': case 'v': case 'V': case 'w':
        case 'W': case 'x': case 'X': case 'y': case 'Y':
        case 'z': case 'Z':
            printf("You type a Consonant keyword %c \n",ch);
            break;

        case '1': case '2': case '3': case '4': case '5':
        case '6':case '7':case '8':case '9':
            printf("You type an Integer keyword %c \n",ch);
            break;

        case '.': case ',': case ':': case ';': case '\'':
        case '!': case '?': case '"': case '-': case '_':
        case '(': case ')': case '[': case ']': case '/':
        //case '':
            printf("You type a Punctuation %c \n",ch);
            break;

        default:
            printf("You type %c \n",ch);
            printf("It's not a Vowel, Consonant, Integer and Punctuation\n");
            break;
    }
    putchar('\a');

    return (0);
}
