#include <cstdio>
#include <cstring>
#define size 20
void KMPMatch(char str1[], char str2[]) {
    int l = strlen(str1), k = strlen(str2), i, j, m;
    bool flag;
    for (i = 0; i <= (l - k); ++i) {
        m = i;
        flag = true;
        for (j = 0; j < k; ++j) {
            if (str1[m++] != str2[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("Pattern found at %d\n", i);
            //return i;
        }
    }
    //return -1;
}

int main() {

    char str1[size] = "AABAACAADAABAABA";
    char str2[size] = "AABA";
    KMPMatch(str1, str2);
    //printf("Pattern found at %d\n", KMPMatch(str1, str2));

    return (0);
}
