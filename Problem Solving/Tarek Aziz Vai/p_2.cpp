#include <cstdio>
#include <cmath>

int main() {

    int n, in[100000], sum[5000], rootResult, j, index, replace;
    rootResult = sqrt(n);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    int tsum = 0, j = 0;
    for (i = 0; i < n; ++i) {
        if (j >= rootResult) {
            sum[i % j] = tsum;
            tsum = 0;
            j = 0;
        }
        tsum += in[i];
        j++;
    }
    if (tsum > 0) {
        sum[i % j] = tsum;
    }

    scanf("%d %d", &index, &replace);
    int tResult = in[index] - replace;
    in[index] = replace;

    sum[index / rootResult] -= tResult;

    int q1, q2, bucketSum = 0, queurySum = 0;

    scanf("%d %d", &q1, &q2);

    if ((q1 / rootResult) == (q2 / rootResult)) {
        for (int k = q1; k <= q2; k++) {
            queurySum += sum[k];
        }
    }
    else {
        for (int k = q1 / rootResult; k <= q2 / rootResult; k++) {
            bucketSum += sum[k];
        }
        int bucketIni = (q1 / rootResult) * rootResult;
        for (int j = bucketIni; j < q1; j++) {
            bucketSum -= in[j];
        }
        int bucketEnd = ((q2 / rootResult) * rootResult) + rootResult - 1;
        for (int j = bucketEnd; j > q2; j--) {
            bucketSum -= in[j];
        }
    }

    return (0);
}
