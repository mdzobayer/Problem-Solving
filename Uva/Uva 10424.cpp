#include <cstdio>
#include <cstring>

int main() {

    char name1[30], name2[30];
    int len, t, s1, s2, i;
    while(gets(name1)) {
        gets(name2);
        len = strlen(name1);
        t = 0;
        for (i = 0; i < len; ++i) {
            if (name1[i] >= 'A' && name1[i] <= 'Z'){
                t += (name1[i] - 64);
            }
            else if (name1[i] >= 'a' && name1[i] <= 'z') {
                t += (name1[i] - 96);
            }
        }
        label:
        s1 = 0;
        while(t != 0) {
            s1 += (t % 10);
            t /= 10;
        }
        if (s1 > 9) {
            t = s1;
            goto label;
        }
        /// Second Name
        len = strlen(name2);
        t = 0;
        for (i = 0; i < len; ++i) {
            if (name2[i] >= 'A' && name2[i] <= 'Z'){
                t += (name2[i] - 64);
            }
            else if (name2[i] >= 'a' && name2[i] <= 'z') {
                t += (name2[i] - 96);
            }
        }
        label1:
        s2 = 0;
        while(t != 0) {
            s2 += (t % 10);
            t /= 10;
        }
        if (s2 > 9) {
            t = s2;
            goto label1;
        }

        if (s1 > s2) {
            printf("%0.2f %%\n",(s2 * 100) /(float) s1);
        }
        else {
            printf("%0.2f %%\n",(s1 * 100) /(float) s2);
        }
    }

    return (0);
}
