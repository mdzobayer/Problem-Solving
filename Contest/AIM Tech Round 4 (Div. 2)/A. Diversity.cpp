#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {

    char str[1010];
    int k, record[130], i, len, sum, uniq;
    std::vector<int> vt;
    memset(record, 0, sizeof(record));
    scanf("%s", &str);
    scanf("%d", &k);
    len = strlen(str);
    if (len < k) {
        printf("impossible\n");
    }
    else {
        for (i = 0; i <= len; ++i) {
            record[str[i]] += 1;
        }
        uniq = 0;
        sum = 0;
        for (i = 97; i <= 122; ++i) {
            if (record[i] > 1) {
                sum += (record[i] - 1);
                uniq += 1;
            }
            if (record[i] == 1)
                uniq += 1;
        }
        //printf("uniq %d sum %d\n", uniq, sum);
        if (uniq >= k) {
            printf("0\n");
            return (0);
        }
        uniq = k - uniq;
        printf("%d\n", uniq);
    }


    return (0);
}
