#include <cstdio>
#include <cstring>

char text[100010];

void manachersAlgorithm(int n) {

    if (n == 0) return;
    n = 2 * n + 1;  /// Position count
    int L[n];       /// LPS length array
    L[0] = 0;
    L[1] = 1;
    int c = 1;      /// Center position
    int r = 2;      /// center right position
    int i = 0;      /// current right position
    int iMirror;    /// current left position
    int expand = -1, diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;

    for (i = 2; i < n; ++i){
        // Get currentLeftPosition iMirror for currentRightPosition
        iMirror = 2 * c - i;
        // Reset expand - means no expansion required
        expand = 0;
        diff = r - i;

        if (diff > 0) {
            if (L[iMirror] < diff) /// Case 1
                L[i] = L[iMirror];
            else if (L[iMirror] == diff && i == n - 1) { // Case 2
                L[i] = L[iMirror];

            }
            else if (L[iMirror] == diff && i < n - 1) { // Case 2
                L[i] = L[iMirror];
                expand = 1; // expansion required
            }
            else if (L[iMirror] > diff) {
                L[i] = diff;
                expand = 1; // expansion required
            }
        }
        else {
            L[i] = 0;
            expand = 1;     // expansion required
        }
        if (expand == 1) {
            while(((i + L[i]) < n && (i - L[i] > 0) &&
                   (((i + L[i] + 1) % 2 == 0) ||
                    (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2]))))
            {
                L[i]++;
            }

            if (L[i] > maxLPSLength)   /// Track maxLPSLength
            {
                maxLPSLength = L[i];
                maxLPSCenterPosition = i;
            }

            // if palindrome cenered at currentRightPosition i
            // expand beyond centerRightPosition r,
            // adjust centerPosition C based on expanded palindrome.
            if (i + L[i] > r) {
                c = i;
                r = i + L[i];
            }
            /// print LPS length
        }
    }
    printf("%d\n", maxLPSLength);
//    start = (maxLPSCenterPosition - maxLPSLength) / 2;
//    end = start + maxLPSLength - 1;
//
//    printf("LPS of string is %s : ", text);
//    for (i = start; i <= end; ++i) {
//        printf("%c", text[i]);
//    }
//    printf("\n");
}

int main() {
    int n;
    while(scanf("%lld", &n) == 1) {
        getchar();
        scanf("%s", &text);
        manachersAlgorithm(n);
    }

    return (0);
}
