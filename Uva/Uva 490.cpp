#include <cstdio>
#include <cstring>

int max (int & x, int & y) {
    if (x > y)
        return x;
    else return y;
}

int main() {

    char sentence[110][110];
    int mxSentence = 0, mxLength = 0, i, j, len;

    for (i = 0; i < 110; ++i)
        for (j = 0; j < 110; ++j)
        sentence[i][j] = ' ';

    while(gets(sentence[mxSentence])) {
        len = strlen(sentence[mxSentence]);
        sentence[mxSentence][len] = ' ';
        mxLength = max(mxLength, len);
        mxSentence++;
    }
    for (i = 0; i < mxLength; ++i) {
        for (j = mxSentence - 1; j >= 0; --j) {
            printf("%c", sentence[j][i]);
        }
        printf("\n");
    }

    return (0);
}
